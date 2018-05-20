using System;
using System.Threading;
/*关于使用【使用Synchronization进行同步】
using System.Runtime.Remoting.Contexts;
[Synchronization]  //Printer类中所有的方法都是线程同步(安全)的
public class Printer
{
 
}
//缺点:即使其中某个(些)方法没有使用线程敏感数据,
//        CLR也一样会锁定对该方法的调用。
//        这样会降低性能。
*/
namespace Ch11.ThreadSynchronization4 {
 
 class Account {
  private double balance;
  private string name;
  
  public Account() { }
  public Account(double num) {
   balance = num;
  }
  
  public Account(double num, string name) : this(num) {
   this.name = name;
  }
  
  public double Balance {
   set {
    balance = value;
   }
   get {
    return balance;
   }
  }
  
  public string Name {
   set {
    name = value;
   }
   get {
    return name;
   }
  }
  
  //存款num元
  public void deposit(double num) {
   balance += num;
  }
  
  //取款num元
  public void withdraw(double num) {
   balance -= num;
  }
 }
 
 public class Program {
  private Account acc = new Account(5000, "Parents");
  
  public static void Main() {
   Thread.CurrentThread.Name = "Parents";
   Program pro = new Program();   
   
   Thread Alice = new Thread(pro.ThreadRun);   
   Thread Tom = new Thread(pro.ThreadRun);
   Thread Mary = new Thread(pro.ThreadRun);
   Thread Jack = new Thread(pro.ThreadRun);
   
   Alice.Name = "Alice";
   Tom.Name = "Tom";
   Mary.Name = "Mary";
   Jack.Name = "Jack";
   
   Alice.Start();
   Tom.Start();
   Mary.Start();
   Jack.Start();
   
   pro.ThreadRun(); //Parents线程
  }
  
  public void ThreadRun() {
   if(Thread.CurrentThread.Name == "Parents") {    
    makeDeposit(5000);    
   } else {
    for(int i = 0; i < 5; i++) {
     makeWithdrawal(1000);
     if(acc.Balance < 0) {
      Console.WriteLine("★★帐户被透支啦!");
     }
    }
   }
   
  }
  
  private void makeDeposit(double num) {
   lock(this) {
    Monitor.Wait(this);  //等待孩子的通知才存钱
    Console.WriteLine("父母在存钱...");
    acc.deposit(num);
    Monitor.PulseAll(this); //通知所有等待的孩子可以去取钱
   }
  }
  
  private void makeWithdrawal(double num) {
   Monitor.Enter(this);
      //lock(this)
   //{
     Console.WriteLine("{0} 要取钱",
                       Thread.CurrentThread.Name);
     if(acc.Balance >= num) { 
       //Thread.Sleep(1);      
      acc.withdraw(num);
      Console.WriteLine("{0} 成功取钱 {1} 元。",
                        Thread.CurrentThread.Name, num);
     } else {
      Console.WriteLine("钱不够 {0} 取, 余额仅 {1} 元。",
                       Thread.CurrentThread.Name, acc.Balance);
      Monitor.Pulse(this); //钱不够了, 通知父母可以存钱了   
     }
   //}
   Monitor.Exit(this);
  }
 }
}
 
