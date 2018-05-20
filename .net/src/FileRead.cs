//FileRead.cs---文件名与相对路径(相对.exe的) 文件读写方式与共享打开方式等 读文件

using System;
using System.IO;

namespace Ch09.Book {
 public class FileRead {
  public void ReadData() {
   //FileStream fs = new FileStream(
   //"01TestStreamReader.cs", //◆与当前.exe在同一目录下
   //FileMode.Open,
   //FileAccess.Read,
   //FileShare.None);
   
   FileStream fs = new FileStream(
    @"..\..\Chap09_IOStream\01TestStreamReader.cs",
    FileMode.Open,
    FileAccess.Read,
    FileShare.Read); 
   //    ▲若为FileShare.None,则其他文件流不能访问同一个文件
   //        但改成FileShare.Read则可以让别的文件同时访问
   FileStream fs2 = new FileStream(
    @"..\..\Chap09_IOStream\01TestStreamReader.cs",
    FileMode.Open,
    FileAccess.Read,
    FileShare.Read); //★fs与fs2访问
        //▲同一个文件时不能是FileShare.None
   
   StreamReader sr = new StreamReader(fs);
   
   //▼让文件指针指向文件的开始位置
   sr.BaseStream.Seek(0, SeekOrigin.Begin);
   
   //▼一直读到文件的结尾
   string str = sr.ReadLine();
   while(str != null) {
    Console.WriteLine("{0}", str);
    str = sr.ReadLine();
   }
   
   //▼关闭StreamReader对象sr和基础的FileStream对象fs
   sr.Close();
   fs.Close();
  }
  
  public static void Test() {
   FileRead fr = new FileRead();
   fr.ReadData();
  }
 }
}
 
 
