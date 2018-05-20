//TestOverflowException.cs --checked上下文，算术运算结果溢出异常，类型转换溢出

using System;
namespace ConsoleApp.Ch08
{
  class TestOverflowException
  {
    public static void Main()
    {
      Test2();  //Test1() ~ Test3()
    }
    public static void Test1()
    {
      int value = 7800;  //try with value 780000000 ?
      checked
      {
        try
        {
          // Square the original value.
          //▼▼算术运算产生的结果超出由运算返回的数据类型的范围
          int square = value * value;  //beyond the range of the target type??
          Console.WriteLine("{0} ^ 2 = {1}", value, square);
        }
        catch (OverflowException)
        {
          double square = Math.Pow(value, 2);　//double
          Console.WriteLine("Exception: {0} > {1:E}.",
                            square, Int32.MaxValue);
        }
      }
      // The example displays the following output:
      //       Exception: 6.084E+17 > 2.147484E+009.
    }
    public static void Test2()
    {
      byte value = 241;
      //int value = 65546;  //65546 = 65536 + 10
      //int value = 65535;
      //int value = 131071;  //131071 = 65536 + 65535
     
     
      //注意在checked上下文（或检查的上下文）中，
      //  强制转换或转换操作尝试执行收缩转换时若
      //    源数据类型的值超出了目标数据类型的范围时：
      //    也会抛出OverflowException异常
     
      checked  //←★试试去掉或加上 checked: 无checked的情形参考Test3()
      {
        try
        {
          sbyte newValue = (sbyte)value;
          Console.WriteLine("Converted the {0} value {1} to the {2} value {3}.",
                            value.GetType().Name, value,
                            newValue.GetType().Name, newValue);
        }
        catch (OverflowException)
        {
          Console.WriteLine("Exception: {0} > {1}.", value, SByte.MaxValue);
        }
      }
      // The example displays the following output:
      //       Exception: 241 > 127.
    }
    public static void Test3()
    {
      //要使算术运算、强制转换操作或转换操作引发 OverflowException，
      //  操作必须发生在所检查的上下文中。
 
      //  默认情况下，在 Visual Basic 中会检查数学运算和溢出；
      //            而在 C# 中不检查数学运算和溢出。
      //  如果操作发生在未检查的上下文中，计算的结果被截断。
      //byte value = 241;
      //int value = 65546;  //65546 = 65536 + 10
      //int value = 65535;
      int value = 131071;  //131071 = 65536 + 65535
      try
      {
        sbyte newValue = (sbyte)value;
        Console.WriteLine("Converted the {0} value {1} to the {2} value {3}.",
                          value.GetType().Name, value,
                          newValue.GetType().Name, newValue);
      }
      catch (OverflowException)
      {
        Console.WriteLine("Exception: {0} > {1}.", value, SByte.MaxValue);
      }
      // The example displays the following output:
      //       Converted the Byte value 241 to the SByte value -15.
    }
  }
}
