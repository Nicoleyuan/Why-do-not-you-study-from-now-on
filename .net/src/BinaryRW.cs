//BinaryRW.cs --二进制文件读写

using System;
using System.IO;
namespace Ch09.Book {
 public class BinaryRW {
  static void BinWrite(String file) {
   //▼下面演示BinaryWriter(二进制写)
   BinaryWriter bw;   
   
   int i = 65546;  //65536 + 10
   double d = 1029.99;
   bool b = true;
   
   try {
    bw = new BinaryWriter(
     new FileStream(file,
                    FileMode.Create));    
   } catch (IOException e) {
    Console.WriteLine(e.Message + "\n不能打开文件.");
    return;
   }
   
   try {
    Console.WriteLine("正在写 " + i);
    bw.Write(i);
    Console.WriteLine("正在写 " + d);
    bw.Write(d);
    Console.WriteLine("正在写 " + b);
    bw.Write(b);
    
    Console.WriteLine("正在写 " + 12.2 * 7.4);
    bw.Write(12.2 * 7.4);
   } catch (IOException e) {
    Console.WriteLine(e.Message + "\n写入文件错误");
   }
   bw.Flush();
   bw.Close();
  }
  
  static void BinRead(String file) {
   //int i = 65546;  //65536 + 10
   double d = 1029.99;
   bool b = true;
   
   //▼下面演示BinaryReader(二进制读)
   BinaryReader br;
   try {
    br = new BinaryReader(
     new FileStream(file,
                    FileMode.Open));
   } catch (IOException e) {
    Console.WriteLine(e.Message + "不能读取文件.");
    return;
   }
   
   try {
    //i = br.ReadInt32();
    //Console.WriteLine("读到Int32: " + i);
    
    short s = br.ReadInt16();
    Console.WriteLine("读到Int16: " + s);    
    s = br.ReadInt16();
    Console.WriteLine("读到Int16: " + s);
    
    //b = br.ReadBoolean();
    //Console.WriteLine("读到Boolean: " + b);
    
    d = br.ReadDouble();
    Console.WriteLine("读到Double: " + d);
    
    b = br.ReadBoolean();
    Console.WriteLine("读到Boolean: " + b);
    
    d = br.ReadDouble();
    Console.WriteLine("读到Double: " + d);
   } catch (IOException e) {
    Console.WriteLine(e.Message + "读数据错误");
   }
   br.Close(); 
  }
  
  public static void Main() {
   //String filename = @"..\..\Chap09_IOStream\testdata"; //??项目文件夹bin中吗
   String filename = @"testdata";
   
   BinWrite(filename);   
   Console.WriteLine();   
   BinRead(filename);
  }
 }
}
 
