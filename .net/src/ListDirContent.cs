//ListDirContent.cs --按目录树形式列出文件夹下的所有目录和文件；递归

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace Ch09
{
  class ListDirContent
  {
    public static void Main()
    {
      Console.WriteLine("请输入文件夹的路径（全名）：");
      string DirName = Console.ReadLine();
      DirectoryInfo dir;
      try
      {
        dir = new DirectoryInfo(DirName);
        Console.WriteLine("文件夹{0}下的资源如下:", dir.FullName);
        DIR(dir, 0);
      }
      catch (Exception e)
      {
        Console.WriteLine(e.Message);
      }
    }
    public static void DIR(DirectoryInfo dir, int indents)
    {
      for (int i = 0; i < indents; i++)
      {
        if (i == indents - 1)
          Console.Write("|-- ");
        else
          Console.Write("|  ");
      }
      Console.WriteLine("{0} <DIR>", dir.Name);
      indents += 1;
      DirectoryInfo[] dirs = dir.GetDirectories();
      FileInfo[] files = dir.GetFiles();
      if (dirs == null || files == null)
        return;
      foreach (DirectoryInfo dd in dirs)
        DIR(dd, indents);  //递归调用
      foreach (FileInfo f in files)
      {
        for (int i = 0; i < indents; i++)
        {
          if (i == indents - 1)
            Console.Write("|-- ");
          else
            Console.Write("|  ");
        }
        Console.WriteLine(f.Name);
      }  //end of foreach
    } //end of DIRs()
  }
}
