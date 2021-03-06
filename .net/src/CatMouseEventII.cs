//CatMouseEventII.cs 基于委托的事件模型，事件参数的传递。委托的声明，基于委托的事件，向事件注册事件响应（处理方法）, 事件的发出

using System;
using System.Threading;
namespace ByPoints.Delegates.CatMouseEventII
{
 /// <summary>
 /// Description of CatMouse.
 /// 〖猫叫一声，老鼠立即逃跑〗 
 /// 根据猫叫的分贝数（10~100db ）, 老鼠以相应的速度逃跑
 ///  分贝数(int: db)  逃跑速度(int: m/s)
 ///       < 40             4
 ///       < 80             8
 ///       >= 80            12
 ///        n         ((n/40) + 1) * 4
 /// </summary>
 
 public class TestCatCall {
  public static void Test() {
   Cat c1 = new Cat("小花猫");
      Cat c2 = new Cat("大黑猫");
      Cat c3 = new Cat("小白猫");
   Mouse m1 = new Mouse("小白鼠");
      Mouse m2 = new Mouse("小黑鼠");
      Mouse m3 = new Mouse("米妮");
      Mouse m4 = new Mouse("大灰鼠");
      Mouse m5 = new Mouse("米奇");
      c1.Calling += m1.Escape;
      c1.Calling += m2.Escape;
      c1.Calling += m3.Escape;
      c2.Calling += m3.Escape;
      c2.Calling += m4.Escape;
      c2.Calling += m5.Escape;
   //猫要叫了：
   int db;
   do {
    Console.WriteLine("\n\n请输入一个介于10 ~ 100之间的" +
                      "整数:(非法数据直接退出)");
    Int32.TryParse(Console.ReadLine(), out db);
    if(db < 10 || db > 100)
     break;
    //Console.WriteLine("猫以 {0} 分贝叫了一声:", db);
    c1.Call(db);
        Thread.Sleep(2000);
        c2.Call(db * 2);
        Thread.Sleep(3000);
        c3.Call(db * 3);
   } while (true);
  }
 } 
 
 class Cat  {
    //字段：猫的名字 name
    private string name;
   
  //下面事件参数类SoundDbEventArgs的定义，包含只读int型成员Db
  public class SoundDbEventArgs : EventArgs {
   public readonly int Db;
   public SoundDbEventArgs(int db) {
    Db = db;
   }
  }
  //代理CatEventHandler
  public delegate void CatEventHandler(object sender, SoundDbEventArgs e);  
  //基于代理的事件Calling--猫叫时引发  
  public event CatEventHandler Calling;
  //猫叫方法--Call, 如果可以，调用事件Calling
    //构造方法
    public Cat(string name)
    {
      this.name = name;
    }
  public void Call(int db) {
      Console.WriteLine("\n猫〔{0}〕以 {1} 分贝叫了一声:", name, db);
      if (Calling != null)
      {  //检查是否有事件注册
        Console.WriteLine("有{0}只老鼠与本猫 〔{1}〕有关：",
          Calling.GetInvocationList().Length, name);
        Calling(this, new SoundDbEventArgs(db)); //调用事件注册的方法
      }
      else
      {
        Console.WriteLine("暂时还没有老鼠在本猫〔{0}〕的领地...", name);
      }
  }  
 }
 //老鼠：猫叫时要逃跑
 class Mouse {
    //字段 老鼠的名字 name 和 逃跑速度 EscVelocity
    private string name;
    private int EscVelocity; //逃跑速度(m/s)
    //构造函数
    public Mouse(string name)
    {
      this.name = name;
    }
    //准备向猫叫事件 Calling 注册的方法：事件的响应程序或事件处理方法
  public void Escape(object sender, Cat.SoundDbEventArgs e) {   
   EscVelocity = ((e.Db / 40) + 1) * 4;
      Console.WriteLine("老鼠〔{0}〕正以 {1} m/s 的速度逃跑！",
        name, EscVelocity);
  }
 }
 
}
 
