using System;
using System.Threading;
namespace AllChapters.ThreadSync
{
 /// <summary>
 /// Description of ThreadSynchronization.
 /// </summary>
 class Account {  //非信用卡帐户，不可透支
  private int balance;  //余额不可小于零
  private string name;
  public static readonly int depositMin = 3000;  //一次存款至少3000
  public static readonly int depositMax = 5000; //一次存款至多6000
  public static readonly int withdrawMin = 500;  //一次取款至少1000
  public static readonly int withdrawMax = 1500; //一次取款最多3000
  public static readonly int maxBalance = 6000; //存款后余额至多达12000
  
  public Account() { }
  public Account(int num) {
   balance = num;
  }
  
  public Account(int num, string name) : this(num) {
   this.name = name;
  }
  
  public int Balance {
   get { return balance; }
  }  
  public string Name {
   set { name = value; }
   get { return name; }
  }
  
  //存款num(◆int兼容类型)元
  public void deposit(int num, int k) { //第k次
   Monitor.Enter(this);   //取得锁才继续  
   Console.Write("" +
                 "【{0}】{1}欲存款 {2} 元, 现余额为 {3} 元",
                 k,
                 Thread.CurrentThread.Name,
                 num,
                 balance);
   if(num < depositMin || num > depositMax)
   {
    Console.WriteLine("\t存款失败, 存款额 d 须满足 : {0} ≤d≤{1}!",
                    depositMin, depositMax);
    goto ToExitDeposit; //return;
   }
   while(balance + num > maxBalance) {
    Console.Write("\n【{0}】{1}存款暂停！若存款{2} 元余额将超出 {3}",
                      k,
                      Thread.CurrentThread.Name,
                      num,
                      maxBalance);
    Console.WriteLine("  孩子们来取钱吧！");
    Monitor.Wait(this); //等待子女取钱
   }    
   balance += num;
   Console.WriteLine(
                     "【{0}】{1} 成功存款 {2} 元, 余额为 {3} 元。",
                     k,
                     Thread.CurrentThread.Name,
                     num,
                     balance);
   Monitor.PulseAll(this);  //通知子女可以取钱了   
  ToExitDeposit:
   Monitor.Exit(this);
  }
  
  //取款num(◆int兼容类型)元
  public void withdraw(int num, int k) {
   Monitor.Enter(this);    
   Console.Write("【{0}】{1} 欲取款 {2} 元, 现余额为 {3} 元: ",
                     k,
                     Thread.CurrentThread.Name,
                     num,
                     balance);
   if(num < withdrawMin || num > withdrawMax)
   {
    Console.WriteLine("取款失败，取款额 w 须满足 : {0} ≤w≤{1}!",
                     withdrawMin, withdrawMax);
    goto ToExitWithdrawal;//return;
   }   
   while(num > balance) {
    Console.WriteLine(
       "【{0}】{1} 取款失败！取款额超过帐户余额，需要爸妈存钱了",
       k, Thread.CurrentThread.Name);
    Monitor.Wait(this);   //等待长辈存钱
   }
   balance -= num;
   Console.WriteLine(
     "【{0}】{1} 成功取款 {2} 元，帐户余额为 {3} 元。",
     k, Thread.CurrentThread.Name, num, balance);
   Monitor.PulseAll(this); //取过钱了，通知父母可以往里存钱了
  ToExitWithdrawal:
   Monitor.Exit(this);
  }
 }
 
 public class ThreadSynchronization
 {
  private static Account acc =
    new Account(Account.maxBalance,
                "Smith"); //开户时存10000
  //▼用于产生随机数
  private static Random ran = new Random();
  static void UI_depos() {
   int i = 0;
   while(true) {
    i++;
    int relax = ran.Next(3000, 4000);  //休息时间：随机的3~4秒
    Thread.Sleep(relax);  //随机休息约3~4秒
    //▼随机存 ..到 .. 元之间的数目
    int money = ran.Next(Account.depositMin,
                         Account.depositMax);
    money = money - money % 1000; //以1000为单位，零头去掉    
    acc.deposit(money, i);   //存几千整了
    if(i >= 5)
     break;
   }
  }
  static void UI_withdr() {
   int i = 0;
   while(true){
    i++;
     //▼随机取..到..元之间的数目
    int money = ran.Next(Account.withdrawMin,
                         Account.withdrawMax);
    money -= money % 500; //以500为单位，零头去掉
    acc.withdraw(money, i); //取1000,1500,2000或2500
    int relax = ran.Next(1500, 2500);  //随机休息约2秒
    Thread.Sleep(relax); //随机休息约1000毫秒
    if(i>=8) break;
   }   
  }
  public static void Main() {
   //父母往帐户中存钱
   Thread Dad = new Thread(UI_depos);
   Thread Mum = new Thread(UI_depos);
   //四个孩子从中取钱
   Thread Alice = new Thread(UI_withdr);
   Thread Tom = new Thread(UI_withdr);
   Thread Mary = new Thread(UI_withdr);
   Thread Jack = new Thread(UI_withdr);   
   
   //设置线程的名称，便于显示当前存取款的线程信息
   Dad.Name = "Dad";
   Mum.Name = "Mum";
   Alice.Name = "Alice";
   Tom.Name = "Tom";
   Mary.Name = "Mary";
   Jack.Name = "Jack";
   //启动这些线程
   Dad.Start();
   Mum.Start();
   Alice.Start();
   Tom.Start();
   Mary.Start();
   Jack.Start();
   
  }
 }
}

/*
【1】Alice 欲取款 500 元, 现余额为 6000 元: 【1】Alice 成功取款 500 元，帐户余额
为 5500 元。
【1】Tom 欲取款 1000 元, 现余额为 5500 元: 【1】Tom 成功取款 1000 元，帐户余额为
 4500 元。
【1】Mary 欲取款 1000 元, 现余额为 4500 元: 【1】Mary 成功取款 1000 元，帐户余额
为 3500 元。
【1】Jack 欲取款 1000 元, 现余额为 3500 元: 【1】Jack 成功取款 1000 元，帐户余额
为 2500 元。
【2】Alice 欲取款 500 元, 现余额为 2500 元: 【2】Alice 成功取款 500 元，帐户余额
为 2000 元。
【2】Tom 欲取款 500 元, 现余额为 2000 元: 【2】Tom 成功取款 500 元，帐户余额为 1
500 元。
【2】Mary 欲取款 1000 元, 现余额为 1500 元: 【2】Mary 成功取款 1000 元，帐户余额
为 500 元。
【2】Jack 欲取款 1000 元, 现余额为 500 元: 【2】Jack 取款失败！取款额超过帐户余
额，需要爸妈存钱了
【1】Mum欲存款 3000 元, 现余额为 500 元【1】Mum 成功存款 3000 元, 余额为 3500 元
。
【2】Jack 成功取款 1000 元，帐户余额为 2500 元。
【3】Tom 欲取款 1000 元, 现余额为 2500 元: 【3】Tom 成功取款 1000 元，帐户余额为
 1500 元。
【3】Alice 欲取款 500 元, 现余额为 1500 元: 【3】Alice 成功取款 500 元，帐户余额
为 1000 元。
【1】Dad欲存款 4000 元, 现余额为 1000 元【1】Dad 成功存款 4000 元, 余额为 5000
元。
【3】Mary 欲取款 500 元, 现余额为 5000 元: 【3】Mary 成功取款 500 元，帐户余额为
 4500 元。
【4】Tom 欲取款 500 元, 现余额为 4500 元: 【4】Tom 成功取款 500 元，帐户余额为 4
000 元。
【3】Jack 欲取款 500 元, 现余额为 4000 元: 【3】Jack 成功取款 500 元，帐户余额为
 3500 元。
【4】Alice 欲取款 1000 元, 现余额为 3500 元: 【4】Alice 成功取款 1000 元，帐户余
额为 2500 元。
【4】Mary 欲取款 500 元, 现余额为 2500 元: 【4】Mary 成功取款 500 元，帐户余额为
 2000 元。
【5】Tom 欲取款 1000 元, 现余额为 2000 元: 【5】Tom 成功取款 1000 元，帐户余额为
 1000 元。
【4】Jack 欲取款 500 元, 现余额为 1000 元: 【4】Jack 成功取款 500 元，帐户余额为
 500 元。
【2】Mum欲存款 4000 元, 现余额为 500 元【2】Mum 成功存款 4000 元, 余额为 4500 元
。
【5】Alice 欲取款 1000 元, 现余额为 4500 元: 【5】Alice 成功取款 1000 元，帐户余
额为 3500 元。
【2】Dad欲存款 4000 元, 现余额为 3500 元
【2】Dad存款暂停！若存款4000 元余额将超出 6000  孩子们来取钱吧！
【5】Mary 欲取款 1000 元, 现余额为 3500 元: 【5】Mary 成功取款 1000 元，帐户余额
为 2500 元。
【2】Dad存款暂停！若存款4000 元余额将超出 6000  孩子们来取钱吧！
【5】Jack 欲取款 1000 元, 现余额为 2500 元: 【5】Jack 成功取款 1000 元，帐户余额
为 1500 元。
【2】Dad 成功存款 4000 元, 余额为 5500 元。
【6】Tom 欲取款 500 元, 现余额为 5500 元: 【6】Tom 成功取款 500 元，帐户余额为 5
000 元。
【6】Alice 欲取款 1000 元, 现余额为 5000 元: 【6】Alice 成功取款 1000 元，帐户余
额为 4000 元。
【3】Mum欲存款 3000 元, 现余额为 4000 元
【3】Mum存款暂停！若存款3000 元余额将超出 6000  孩子们来取钱吧！
【6】Mary 欲取款 1000 元, 现余额为 4000 元: 【6】Mary 成功取款 1000 元，帐户余额
为 3000 元。
【3】Mum 成功存款 3000 元, 余额为 6000 元。
【7】Tom 欲取款 500 元, 现余额为 6000 元: 【7】Tom 成功取款 500 元，帐户余额为 5
500 元。
【6】Jack 欲取款 1000 元, 现余额为 5500 元: 【6】Jack 成功取款 1000 元，帐户余额
为 4500 元。
【7】Alice 欲取款 500 元, 现余额为 4500 元: 【7】Alice 成功取款 500 元，帐户余额
为 4000 元。
【3】Dad欲存款 4000 元, 现余额为 4000 元
【3】Dad存款暂停！若存款4000 元余额将超出 6000  孩子们来取钱吧！
【7】Mary 欲取款 1000 元, 现余额为 4000 元: 【7】Mary 成功取款 1000 元，帐户余额
为 3000 元。
【3】Dad存款暂停！若存款4000 元余额将超出 6000  孩子们来取钱吧！
【8】Tom 欲取款 500 元, 现余额为 3000 元: 【8】Tom 成功取款 500 元，帐户余额为 2
500 元。
【3】Dad存款暂停！若存款4000 元余额将超出 6000  孩子们来取钱吧！
【7】Jack 欲取款 500 元, 现余额为 2500 元: 【7】Jack 成功取款 500 元，帐户余额为
 2000 元。
【3】Dad 成功存款 4000 元, 余额为 6000 元。
【8】Alice 欲取款 1000 元, 现余额为 6000 元: 【8】Alice 成功取款 1000 元，帐户余
额为 5000 元。
【4】Mum欲存款 3000 元, 现余额为 5000 元
【4】Mum存款暂停！若存款3000 元余额将超出 6000  孩子们来取钱吧！
【8】Mary 欲取款 500 元, 现余额为 5000 元: 【8】Mary 成功取款 500 元，帐户余额为
 4500 元。
【4】Mum存款暂停！若存款3000 元余额将超出 6000  孩子们来取钱吧！
【8】Jack 欲取款 1000 元, 现余额为 4500 元: 【8】Jack 成功取款 1000 元，帐户余额
为 3500 元。
*/
