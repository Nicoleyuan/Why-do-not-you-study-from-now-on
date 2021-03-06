//TestThread1.cs --System.Threading命名空间; Thread; ThreadStart委托；线程栈

using System;
using System.Threading;  //for Thread clas
namespace ConsoleApp.Ch09
{
  class TestThread1
  {
    public static void Test() //Executed as main thread
    {
      Console.WriteLine("Main Thread BEGIN");
      Thread t1 = new Thread(ThreadDo);
      t1.Name = "J";
      t1.Start();
      Thread t2 = new Thread(ThreadDo);
      t2.Name = "S";
      t2.Start();
      for (int i = 0; i < 200; i++)
      {
        Console.Write("M:{0,3} ", i);
      }
      //using a ThreadStart--delegate type’s variable/object
      //  as Thread’s Constructor’s parameter:
      ThreadStart ts = new ThreadStart((new TestThread1()).f);
      Thread f = new Thread(ts);
      f.Name = "Instance’s Method f";
      f.Start();
      Console.WriteLine("Main Thread END.");
    }
    public void f()
    {
      Console.WriteLine("{0} Thread BEING.",
        Thread.CurrentThread.Name);
      for (int i = 0; i < 10; i++)
      {
        Console.Write("{0}:{1,2} ",
          Thread.CurrentThread.Name, i);
      }
      Console.WriteLine("{0} Thread END.",
        Thread.CurrentThread.Name);
    }
    public static void ThreadDo()
    {
      Console.WriteLine("{0} Thread BEING.",
        Thread.CurrentThread.Name);
      for (int i = 0; i < 50; i++)
      {
        Console.Write("{0}:{1,2} ",
          Thread.CurrentThread.Name, i);
      }
      Console.WriteLine("{0} Thread END.",
        Thread.CurrentThread.Name);
    }
  }
}
