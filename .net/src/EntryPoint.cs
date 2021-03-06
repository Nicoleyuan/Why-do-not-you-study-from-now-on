//EntryPoint.cs -- 反射与运行时类型及成员发现，方法及构造方法的动态调用

using System;
//using ByPoints.Attributes;
using System.Reflection;
namespace ByPoints.Reflections
{
  class Point {
    public int x;
    public int y;
    /*public Point() {
      x = 1;
      y = 1;
    }*/
    public Point(int x, int y) {
      this.x = x;
      this.y = y;
     
    }
    public static Point operator+(Point p1, Point p2) {
      return new Point(p1.x + p2.x, p1.y + p2.y);
    }
    public override string ToString() {
      return string.Format("({0}, {1}) ", x, y);
    }
  }
  public class EntryPoint
  {
    public static void Test()
    {
      //Point p = new Point();
      Type type = typeof(Point);
      object obj1 = null;
      object obj2 = null;
      foreach (ConstructorInfo ctor in type.GetConstructors())
      {
        if (ctor.GetParameters().Length == 0) {
          obj1 = ctor.Invoke(null);
          obj2 = ctor.Invoke(null);
          break;
        }
        else if (ctor.GetParameters().Length == 2)
        {
          obj1 = ctor.Invoke(new object[] { 1, 1 });
          obj2 = ctor.Invoke(new object[] { 99, 99 });
        }
        else
          continue;
      }
     
      if(obj1 != null)
        Console.WriteLine("obj1:{0}", obj1); //Point上的ToString()
      if(obj2 != null)
        Console.WriteLine("obj2:{0}", obj2); //Point上的ToString()
     
      foreach (MethodInfo method in type.GetMethods())
      {
        Console.WriteLine("\n===========方法============");
        Console.WriteLine("方法名: {0}.", method.Name);
        Console.WriteLine("====方法的参数====");
        foreach (ParameterInfo p in method.GetParameters())
        {
          Console.WriteLine("参数名:{0}, 参数类型{1}",
              p.Name, p.ParameterType.Name);         
        }
        if (method.Name == "op_Addition"
            && method.GetParameters().Length == 2)
        {
          object obj3 = method.Invoke(obj1,
                               new object[] { obj1, obj2 });
          Console.WriteLine("obj3: {0}", obj3);
        }
        if (method.GetParameters().Length == 2)
        {
          //下面的这行调用适用于 带两个int兼容参数并返回double值的方法
          //double result = (double)(method.Invoke(obj, new object[] { 15, 3 }));
          //Console.WriteLine("result = {0}", result);
         
         
        }
      }
    }
  }
}
