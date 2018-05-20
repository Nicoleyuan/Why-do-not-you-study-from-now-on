//public static void Sum<T>(out T result, params T[] array) --泛型方法求和

using System;
using System.Collections.Generic;
//using System.Reflection; //暂时不使用反射机制
namespace ConsoleApp.Ch04
{
  class Person
  {
    private string name;
    public Person(string name) { this.name = name; }
    public override string ToString()
    {
      return string.Format("name: {0}", name);
    }
  }
  class Point
  {
    public int x;
    public int y;
    public Point()
    {
      x = 1;
      y = 1;
    }/**/
    public Point(int x, int y)
    {
      this.x = x;
      this.y = y;
    }
    public static Point operator ++(Point p)
    {
      //return new Point(p.x+1, p.y+1);
      p.x++;
      p.y++;
      return p;
    }
    public static Point operator +(Point p1, Point p2)
    {
      return new Point(p1.x + p2.x, p1.y + p2.y);
    }
    public override string ToString()
    {
      return string.Format("({0}, {1}) ", x, y);
    }
  }
  class TestGenericMethod
  {
    public static void Test()
    {
      Console.WriteLine("第 1 次：测试double数组元素加法求和");
      double result;
      double[] arr = new double[] { 2, 3.14, 5, 7, 9.78 };
      Sum<double>(out result, arr);
      Console.WriteLine("result = {0} ", result);
      Console.WriteLine("\n第 2 次：测试string数组元素加法");
      string welcome;
      string[] strArr = new string[] { null, "Hello! ", "Welcome", " to ", "Yangzhou!" };
      Sum<string>(out welcome, strArr);
      Console.WriteLine("welcome = ’{0}’.", welcome);
      Console.WriteLine("\n第 3 次：测试 Point元素相加");
      Point target;
      //如果Point声明为结构类型，则不可以为Sum<Point>(...)传递null参数。
      Sum<Point>(out target, null, new Point(-1, -1), null, new Point(2, 2), new Point(3, 3));
      //Sum<Point>(out target, new Point(-1, -1), new Point(2, 2), new Point(3, 3)); //Point结构可调用本行
      Console.WriteLine("target = {0}.", target);
      Console.WriteLine("\n第 4 次：测试 Person元素相加");
      Person stu;
      Sum<Person>(out stu, new Person("Alan Turing"), new Person("Albert Einstein"));
    }
    public static void Sum<T>(out T result, params T[] array)
        //where T : struct
    {
      if (array.Length > 0)
        result = array[0];
      else
        result = default(T); //类型T的默认值：0、false或null
      dynamic sum = result;
      Type type;
      bool isValueType;
      try
      {
        type = result.GetType();
        isValueType = type.IsValueType; //T是值类型可直接加（哪怕是默认值0等）
      }
      catch (Exception ex)
      {
        Console.WriteLine("第 1 个try-catch: {0}",ex.Message);
        isValueType = false;
      }
      //T如果是引用类型（即不是值类型）：非null则可加，为null则不可加（也不用加，否则null引用异常）
      for (int i = 1; i <= array.Length - 1; i++)
      {
        try
        {
          // 若是引用类型且sum与当前元素均非空，则加；或者值类型也直接可加
          if ( (!isValueType && sum != null && array[i] != null) || isValueType)
            sum = sum + array[i];
          //若是引用类型且sum为空时，sum可直接赋值为下一个元素（不管下一个元素是否为null了）
          else if(!isValueType && sum == null)
            sum = array[i];
        }
        catch (Exception ex)
        {
          Console.WriteLine("第 2 个try-catch: {0}", ex.Message);
          Console.WriteLine("请检查每一个实参元素是否可加!");
          //Console.WriteLine(ex.Message);
          break; // 有异常时，直接退出循环
        }
      }
      result = sum;     
    }
  }
}
