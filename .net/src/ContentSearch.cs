//目录下面按文件扩展名搜索，文件的属性，文件/文件夹的创建与删除

using System;
using System.IO;
namespace Ch09.Book {
 public class TestDirectoryInfo {
  private static DirectoryInfo dir =
   new DirectoryInfo(@"C:\Windows");
  public static void Test() {
   Console.WriteLine("**** Fun with Directory(Info) ****\n");
   
   //Test4();
     
  }
  
  //输出目录信息
  static void Test1() {
   // 绑定到当前应用程序目录
   //DirectoryInfo dir = new DirectoryInfo(".");   
   
   //打印目录信息
   Console.WriteLine("**** Directory Info ****\n");
   Console.WriteLine("FullName(目录全名): {0}",
                    dir.FullName);
   Console.WriteLine("Name(目录名): {0}",
                    dir.Name);
   Console.WriteLine("Parent(父目录): {0}",
                    dir.Parent);
   Console.WriteLine("Creation(创建时间): {0}",
                    dir.CreationTime);
   Console.WriteLine("Attributes: {0}", dir.Attributes);
   Console.WriteLine("Root: {0}", dir.Root);
   Console.WriteLine("************************\n");
  }
  
  //列出文件或子目录信息(指定类型文件或指定模式的目录)
  static void Test2() {
   dir = new DirectoryInfo(@"C:\Windows");
   //TT1();
   //TT2();
   TT3();
  }
  static void TT1() {
   //获取所有的.bmp文件
   FileInfo[] bmpFiles = dir.GetFiles("*.bmp");
   //共找到多少.bmp文件
   Console.WriteLine("找到 {0} 个 *.bmp 文件\n",
                    bmpFiles.Length);
   
   //输出每个文件的信息
   foreach(FileInfo f in bmpFiles) {
    Console.WriteLine("************************\n");
    Console.WriteLine("Name(文件名): {0}", f.Name);
    Console.WriteLine("FullName: {0}", f.FullName);
    Console.WriteLine("Length(文件大小): {0}",
                     f.Length);
    Console.WriteLine("CreationTime(创建时间): {0}",
                     f.CreationTime);
    Console.WriteLine("Attributes: {0}", f.Attributes);
    Console.WriteLine("************************\n");
   }
  }
  static void TT2() {
   FileInfo[] allFiles = dir.GetFiles();
   Console.WriteLine("共有文件{0}个", allFiles.Length);
   DirectoryInfo [] allDirs = dir.GetDirectories();
   Console.WriteLine("共有子目录{0}个", allDirs.Length);  
   
   foreach(DirectoryInfo di in allDirs) {
    Console.WriteLine("Name: {0}", di.Name);
   }
  }
  static void TT3() {
   DirectoryInfo[] CDirs = dir.GetDirectories("*s");
   Console.WriteLine("字符s结尾的子目录{0}个",
                    CDirs.Length);
   foreach(DirectoryInfo di in CDirs) {
    Console.WriteLine("Name: {0}", di.Name);
   }
  }
  
  //创建子目录
  static void Test3() {
   dir = new DirectoryInfo(@"D:\A");
   //在目录dir下创建子目录\MyFoo
   dir.CreateSubdirectory("MyFoo");
   //在目录dir下创建子目录\MyBar\MyZae
   dir.CreateSubdirectory(@"MyBar\MyZae");
   
   //▼CreateSubdirectory方法的返回值
   //   为新建的DirectoryInfo对象
   DirectoryInfo dd =
    dir.CreateSubdirectory(@"MyFooII");
   
   //                                显示dd的目录全路径▼▼
   Console.WriteLine("Created : {0}", dd.FullName);
   
   //    ▼这里用的是dd: 在dd下创建子目录
   dd = dd.CreateSubdirectory(@"MyBarII\MyQaaz");
   Console.WriteLine("Created : {0}", dd.FullName); 
  }
  
  //试图删除带子目录的某个目录
  static void Test4() {
   Test3();  //调用Test3()创建目录
   
   //*
   DirectoryInfo d = new DirectoryInfo(@"D:\A\MyFoo");
   d.Delete();  //空的目录可以直接删除
   Console.WriteLine("删除目录MyFoo成功\n");
   
   //★试图删除子目录MyFooII(连\MyBarII\MyQaaz一起) 
   DirectoryInfo dd = new DirectoryInfo(@"D:\A\MyFooII");
   try {
    dd.Delete();  //目录非空
    Console.WriteLine("目录MyFooII删除成功!:-)");
   } catch (IOException e) {
    Console.WriteLine(e.Message);
    Console.WriteLine("删除目录MyFooII错误啦!:-)\n");
   }   
   /*
   try {   //            ▼
    dd.Delete(true); //递归删除: 就算非空，也一起删除
    Console.WriteLine("目录删除MyFooII成功!:-)");
   } catch (IOException e) {
    Console.WriteLine(e.Message);
    Console.WriteLine("删除目录MyFooII错误啦!:-)\n");
   }
   */
  }   
 }
}
