//TestThread5.cs --线程优先级

using System;
using System.Threading;
namespace ConsoleApp.Ch09
{
  class TestThread5
  {
    public static void ChildThread1()
    {
      Console.WriteLine("子线程1启动了.");
      Console.WriteLine("子线程1--从1数到10....");
      for (int T = 1; T < 11; T++)
      {
        for (int cnt = 0; cnt < 100; cnt++)
        {
          Console.Write(".");
        }
        Console.Write("{0}", T);
      }
      Console.WriteLine("子线程1(优先级为 {0} )结束了.",
                        Thread.CurrentThread.Priority);
    }
    public static void ChildThread2()
    {
      Console.WriteLine("子线程2启动了.");
      Console.WriteLine("子线程2--从11数到20....");
      for (int T = 11; T < 21; T++)
      {
        for (int cnt = 0; cnt < 100; cnt++)
        {
          Console.Write("△");
        }
        Console.Write("{0}", T);
      }
      Console.WriteLine("子线程2(优先级为 {0} )结束了.",
                        Thread.CurrentThread.Priority);
    }
    public static void Main()
    {
      Console.WriteLine("Main -- 创建两个子线程....");
      Thread thr1 = new Thread(ChildThread1);
      Thread thr2 = new Thread(ChildThread2);
      thr2.Priority = ThreadPriority.Highest;  //设置线程优先级
      thr1.Priority = ThreadPriority.Lowest;  //设置线程优先级

      thr2.Start();
      thr1.Start();
    }
  }
}
