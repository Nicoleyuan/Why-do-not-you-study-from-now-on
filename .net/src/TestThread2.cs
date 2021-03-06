//TestThread2.cs --线程方法带参数时，不能使用ThreadStart委托

using System;
using System.Threading;
namespace ConsoleApp.Ch09
{
  class TestThread2
  {
    //◆②③       线程方法的参数:object类型▼
  public static void ChildThreadCall(object obj) {
   Console.WriteLine("Child Thread Start.");
   int sleepTime = 5000;
   Console.WriteLine("Child Thread take a rest for {0} seconds.", sleepTime/1000);
   
   Thread.Sleep(sleepTime);  //休息5秒
   Console.WriteLine("Child Thread Wake up.");
   //Console.WriteLine(obj); //For ◆③-1
   
   //▼下面4行, For ◆③-2:
   /*foreach(int e in ((int[])obj)) {
    Console.Write(e + " ");
   }
   Console.WriteLine();*/
  }
  
  public static void Main() {
   Console.WriteLine("Main - Creating child thread....");
      //▼【①】
   /*Thread childThread = new Thread(ChildThreadCall); //◆①
   childThread.Start(); */
   
   //▼【②】If a method with parameters runs as a thread,
      //   we can not use delegate —— ThreadStart’s object▼
   //ThreadStart ts = new ThreadStart(ChildThreadCall); //◆②
   //Thread thr = new Thread(ts); //◆②
   //thr.Start(999);  //◆②
   
      //▼【③】
   Thread thr = new Thread(ChildThreadCall); //◆③
   thr.Start("Hello");  //◆③-1: parameters can be of any type
   //thr.Start(new int []{1,2,3,4,5,6});//◆③-2:
   
   Console.WriteLine("Main - Starting child thread.");   
  }
  }
}
 
