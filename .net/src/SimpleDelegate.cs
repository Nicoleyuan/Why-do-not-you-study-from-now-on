using System;
namespace ByPoints.Delegates.SimpleDelegate
{
 /// <summary>
 /// Description of SimpleDelegate.
 /// </summary>
 //下面的委托可以指向任何传入两个整数并返回一个整数的方法
 public delegate int BinaryOp(int x, int y);
 
 //下面这个类中包含了BinaryOp将指向的方法
 public class SimpleMath {
  public static int Add(int x, int y) {
   return x + y;
  }
  public static int Subtract(int x, int y) {
   return x - y;
  }
  
  //①下面是类型（参数、返回值）不匹配的函数
  public static int SquareNumber(int x) {
   return x * x;
  }
  //②下面是非静态的NSAdd方法
  public int NSAdd(int x, int y) {
   return x + y;
  }
 }
 
 public class SimpleDelegate {
  //③通过迭代由GetInvocationList()返回的System.Delegate数组，
  //    调用每个对象的Target和Method属性:
  static void DisplayDelegateInfo(Delegate delObj) {
   foreach(Delegate d in delObj.GetInvocationList()) {
    Console.WriteLine("方法: {0} ", d.Method);
    Console.WriteLine("目标类型: {0}", d.Target);
   }
  }
  
  
  public static void Test() {  //或换成Main，单独测试运行
   //创建一个指向SimpleMath.Add()方法的BinaryOp对象
   BinaryOp bo = new BinaryOp(SimpleMath.Add);
   
   //使用委托间接调用Add方法
   //Console.WriteLine("10 + 10 is {0}.", bo(10, 10));
   Console.WriteLine("10 + 10 is {0}.", bo.Invoke(10, 10));
   
   //①编译错误！方法不匹配
   //BinaryOp bo1 = new BinaryOp(SimpleMath.SquareNumber);
   //Console.WriteLine("9 * 9 is {0}.", bo1(9));
   
   //②.NET委托与可以指向实例方法
   BinaryOp bo2 = new BinaryOp(new SimpleMath().NSAdd);
   Console.WriteLine("20 + 30 is {0}.", bo2(20, 30));
   
   //③显示委托对象的信息:
   DisplayDelegateInfo(bo);
   DisplayDelegateInfo(bo2);
   
   bo += new SimpleMath().NSAdd;
   DisplayDelegateInfo(bo);
   
   Console.ReadKey();
  }
 }
}
