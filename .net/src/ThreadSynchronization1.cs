//ThreadSynchronization1.cs --没有做同步

using System;
using System.Threading;
namespace Ch11.ThreadSynchronization1 {
 
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
   //set {
   // balance = value;
   //}
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
    Console.WriteLine("{0} 存款失败，存款额不能为零或负数!",
                      Thread.CurrentThread.Name);
   }
  }
  
  //取款num(◆double兼容类型)元
  public void withdraw(object onum) {
   Console.WriteLine("线程: {0}", Thread.CurrentThread.Name);
   double num = (System.Double)onum;
   if(num > balance) {
    Console.WriteLine("{0}取款失败，取款额超过现有帐户余额，" +
                      "当前帐户余额为 {1} 元",
                      Thread.CurrentThread.Name,
                      balance);
   } else {
    Thread.Sleep(100);  //现在是可以取钱, 不过先体息一小会, 再取不迟
    balance -= num;
    Console.WriteLine("{0}成功取款 {1} 元，帐户余额为 {2} 元。",
                     Thread.CurrentThread.Name,
                     num,
                     balance);
   }
  }
 }
 
 public class Program {
  public static void Main() {
   //▼帐户初始资金￥10000
   Account acc = new Account(10000, "Father Simith");
   
   Thread Alice = new Thread(acc.withdraw);   
   Thread Tom = new Thread(acc.withdraw);
   Thread Mary = new Thread(acc.withdraw);
   Alice.Name = "Alice";
   Tom.Name = "Tom";
   Mary.Name = "Mary";
   
   Alice.Start(2600.0);
   Tom.Start(5700.0);
   Mary.Start(4200.0);
  }
 }
}
 
 
