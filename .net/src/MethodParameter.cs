//MethodParameter.cs Order(三个数)

using System;
using System.Collections.Generic;
namespace ConsoleApp.Experiment2
{
  class MethodParameter
  {
    public static void Order(params int[] arr)
    {
      Array.Sort(arr);  //这种方式默认是顺序排序
    }
    public static void Order(
      ref int a, ref int b, ref int c)
    {
      if (a < b)
      {
        Swap(ref a, ref b);
      }
      if (c > a)
      {javascript:void(0)
        int temp = c;
        c = b;
        b = a;
        a = temp;
      }
      else if (c > b)
      {
        Swap(ref b, ref c);
      }
    }
    public static void Swap(ref int m, ref int n)
    {
      int temp = m;
      m = n;
      n = temp;
    }
  }
}
