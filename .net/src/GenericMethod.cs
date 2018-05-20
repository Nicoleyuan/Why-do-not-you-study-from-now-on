//GenericMethod.cs  泛型方法
using System;
namespace ClassApp.Ch04
{
  /// <summary>
  /// Description of GenericMethod.
  /// </summary>
  public class GenericMethod
  {
    public static void Test()
    {
      double k = Max(3.14, 2.46, -1, 8.88);
      Console.WriteLine(k);
     
      //Student在ClassApp.Ch04 ArrayMethod.cs文件中有定义
      //且实现了IComparable接口，按姓名顺序排序
      Student[] stuArr = {
        new Student(101, "姬发"),  //周武王
        new Student(102, "伊尹"),  //辅佐商朝君王打下天下的贤臣
        new Student(103, "管仲"),  //畏佐齐桓公称霸诸侯的历史名臣
        new Student(104, "颜渊")  //孔子最钟爱的弟子, 以贤著名
      };
      Student s = Max<Student>(stuArr);  //<Student>可省略
      Console.WriteLine("\n按姓名顺序，同学\n  {0}  应该排在最后.", s);     
    }
   
    public static T Max<T>(params T[] arr) where T : IComparable
    {
      T max = arr[0];
      for(int i = 1; i < arr.Length; i++)
      {
        //if(max < arr[i])  //编译Error： "<"无法应用于 T 类型的数
        if(max.CompareTo(arr[i]) < 0)
          max = arr[i];
      }
      return max;
    }
  }
}
 
