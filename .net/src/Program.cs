// Program.cs Order(三个数）
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace ConsoleApp
{
  class Program
  {
    static void Main(string[] args)
    {
      do
      {
        Console.WriteLine("请输入三个整数:(中间以逗号隔开)");
        Console.WriteLine("非法字符退出...");
        string numStr = Console.ReadLine();
        string[] nums = numStr.Split(’,’);
        //string stringObj.Split(params char[] separator);
        int[] numArr = new int[nums.Length];
        bool legal = true; //合法标志
        for (int i = 0; i < numArr.Length; i++)
        {
          legal = int.TryParse(
              nums[i], out numArr[i]);
        }
        if (!legal)
          break;
        Experiment2.MethodParameter.Order(numArr);
        //Experiment2.MethodParameter.Order(ref numArr[0],
        //  ref numArr[1], ref numArr[2]);
        //int a = 22, b = 11, c = 13;
        //Experiment2.MethodParameter.Order(ref a, ref b, ref c);
        //Console.WriteLine("After Ordered, a={0}, b={1}, c={2}.",
        //  a, b, c);
        foreach (int e in numArr)
        {
          Console.Write("{0}  ", e);
        }
      } while (true);
      Console.WriteLine("按任意键退出...");
      Console.ReadKey();
    }
  }
}
