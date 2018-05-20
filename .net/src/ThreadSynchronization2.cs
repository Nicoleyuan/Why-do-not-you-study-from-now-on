//ThreadSynchronization2.cs --同步

using System;
using System.Threading;
namespace Ch11.ThreadSynchronization2 {
 
 class Account {
    //监视器要锁定的成员对象
    private object lockobj = new object();
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
  
  //存款num(◆double兼容类型)元
  public void deposit(object onum) {
   Console.WriteLine("线程: {0}", Thread.CurrentThread.Name);
   double num = (double)onum;
   if(num > 0) {
    balance += num;
    Console.WriteLine( "{0} 成功存款 {1} 元, 余额为 {2} 元。",
                      Thread.CurrentThread.Name,
                     num, balance);
   } else {
    Console.WriteLine("存款失败，存款额不能为零或负数!");
   }
  }
  
  //取款num(◆double兼容类型)元
  public void withdraw(object onum) {
      Console.WriteLine(Thread.CurrentThread.Name + "等待了没有");
   lock(lockobj) {
      //Monitor.Enter(lockobj); //锁定对象lockobj
      Console.WriteLine("线程: {0}", Thread.CurrentThread.Name);
      double num = (System.Double)onum;
      if(num > balance) {
       Console.WriteLine("取款失败，取款额超过现有帐户余额，" +
                       "当前帐户余额为 {0} 元", balance);
      } else {
       Thread.Sleep(100);  //现在是可以取钱, 不过先体息一小会, 再取不迟
       balance -= num;
       Console.WriteLine("成功取款 {0} 元，帐户余额为 {1} 元。",
                       num, balance);
      }
      //Monitor.Exit(lockobj);
   } //end of lock(this)   
  }
 }
 
 public class Program {
  public static void Main() {
   //▼帐户初始资金￥10000
   Account acc = new Account(10000, "Father Simith");
   
   Thread Alice = new Thread(acc.withdraw);   
   Thread Tom = new Thread(acc.withdraw);
   Thread Mary = new Thread(acc.withdraw);
   
   ParameterizedThreadStart pts =
    new ParameterizedThreadStart(acc.withdraw);
   Thread Jack = new Thread(pts);
   
   Alice.Name = "Alice";
   Tom.Name = "Tom";
   Mary.Name = "Mary";
   Jack.Name = "Jack";
   
   Alice.Start(2600.0);
   Jack.Start(2500.0);
   Tom.Start(3200.0);
   Mary.Start(4100.0);   
  }
  //两次运行结果可能不一样
 }
}
 
