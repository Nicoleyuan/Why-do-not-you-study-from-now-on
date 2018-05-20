//TestThread3.cs --线程方法Sleep, Abort, ThreadAbortException

using System;
using System.Threading;
namespace ConsoleApp.Ch09
{
  class TestThread3
  {
    public static void ChildThreadCall()
    {
      Console.WriteLine("线程名:" + Thread.CurrentThread.Name);
      try
      {
        Console.WriteLine("子线程启动了.");
        Console.WriteLine("子线程 - 数到10....");
        for (int i = 0; i < 10; i++)
        {
          Thread.Sleep(500);
          Console.Write("{0} ... ", i);
        }
        Console.WriteLine("子线程结束了.");
      }
      catch (ThreadAbortException e)
      {
        Console.WriteLine(e.Message);
        Console.WriteLine("出现了ThreadAbortException.");
      }
      finally
      {
        Console.WriteLine("in finally{}, 线程名:"
                          + Thread.CurrentThread.Name);
        Console.WriteLine("当前线程的状态:"
                        + Thread.CurrentThread.ThreadState);
      }
      //▼▼如果上面有异常捕获,将无法执行到这里▼▼
      Console.WriteLine("线程名:"
                        + Thread.CurrentThread.Name);
    }
    public static void Main()
    {
      Thread.CurrentThread.Name = "【主线程Main】";
      Console.WriteLine("Main - 正在创建子线程");
      Thread childThread = new Thread(ChildThreadCall);
      Console.WriteLine("Main - 正在启动子线程....");
      childThread.Name = "【子线程childThread】";
      childThread.Start();
      //给子线程时间来运行一小会
      Console.WriteLine("Main - 休息两秒钟....");
      Thread.Sleep(2000);  //当前线程(主线程)休息两秒
      Console.WriteLine("\nMain - 正在终止子线程..");
      childThread.Abort();  //终止线程childThread
    }
  }
}
