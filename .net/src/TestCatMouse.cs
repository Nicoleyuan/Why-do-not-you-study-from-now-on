//TestCatMouse.cs 接口回调实现事件联动

using System;
using System.Collections;
namespace ByPoints.Interface.CatMouseCallback
{
  /// <summary>
  /// Description of TestCatMouse.
  /// 〖猫大叫一声，所有的老鼠都开始逃跑，主人被惊醒。〗
  /// 要点：
    //  1. 联动效果，运行代码只要执行CatObj.Cry()方法。
    //  2. 对老鼠和主人进行抽象
    // 
    //    <1>构造出Cat、Mouse、Master三个类，并能使程序运行
    //    <2>从Mouse和Master中提取抽象
    //    <3>联动效应，只要执行CatObj.Cry()就可以使老鼠逃跑，主人惊醒
  /// </summary>
  ///
  interface Observer {   //客体：信号的接收者
    void Response(); //观察者(老鼠与主人对猫)的响应(如：逃走、惊醒)
  }
  interface Subject {   //主体：信号的发出者
    void AimAt(Observer obs);  //猫的捕捉行为针对哪些观察者?
  } 
  //观察者之一：老鼠
  class Mouse : Observer {
    private string name;
    public Mouse(string name, Subject subj) {
      this.name = name;
      subj.AimAt(this);
    }
    public void Response() { //老鼠的反应
      Console.WriteLine("{0} tried to escape!", name);
    }
  } 
  //观察者之二：主人
  class Master : Observer {
    private string name;
    public Master(string name, Subject subj) {
      this.name = name;
      subj.AimAt(this);
    }      
    public void Response()  //主人的反应
    {
      Console.WriteLine("主人 {0} woke up!", name);
    }
  }
  //主体：猫
  class Cat : Subject {
    private ArrayList observers; //被猫骚扰的一些客体
    public Cat() {
      this.observers = new ArrayList();
    }
    public void AimAt(Observer obs) {
      this.observers.Add(obs);
    }
    public void Cry() {
      Console.WriteLine("猫叫了: Miao~~");
      foreach(Observer obs in observers) {
        obs.Response();
      }
    }
  }
  public class TestCatMouse
  {
    public static void Main() {
      Cat c = new Cat();
      Mouse wms= new Mouse("小白鼠", c);
      Mouse yms = new Mouse("小灰鼠", c);
      Master jing = new Master("郭靖", c);
      Master kang = new Master("杨康", c);
      c.Cry();
    }   
  }
}
