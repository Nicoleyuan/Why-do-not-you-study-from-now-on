//FileWrite.cs --字符方式写文件

using System;
using System.IO;
namespace Ch09.Book {
 public class FileWrite {
  public static void WriteData(string filestr) {
   FileStream fs = new FileStream(
    filestr,
    
    FileMode.Append, //存在:附加到末尾; 不存在:创建
    //FileMode.Create, //创建(有则重新创建)
    //FileMode.CreateNew, //创建新文件(有则创建失败:运行异常) 
    //FileMode.Open,  //打开(不存在时会打开失败:运行异常)
    //FileMode.OpenOrCreate, //打开(不存在时就创建)
    //FileMode.Truncate, //打开(打开后清空)
    
    FileAccess.Write,
    FileShare.None);
   
   StreamWriter sw = new StreamWriter(fs);
   
   //提示用户输入要写进文件中的内容
   Console.WriteLine("请输入字符串(新行上直接回车退出):");
   
   //将用户输入的串保存在str中
   string str = Console.ReadLine();
   
   //▼若直接回车将退出下面的循环
   while(str.Length != 0) {
    //利用StreamWriter对象将字符串str写进文件中
    sw.WriteLine(str);
    
    //Flush()强制StreamWriter对象sw的所有缓冲数据
    //           写入所基于的文件流, 同时清空
    //           对象sw的所有缓冲数据
    sw.Flush();
    
    str = Console.ReadLine();
   }
   
   
   //关闭当前StreamWriter对象sw和所基于的FileStream对象
   sw.Close();
   fs.Close();
  }
  
  public static void Main() {
   string file = @"test.txt";  //与.exe在同一个文件夹
   FileWrite.WriteData(file);
   Console.WriteLine("\n");
   
   FileRead.ReadData(file);
  }
 }
 
 public class FileRead {
  public static void ReadData(string file) {
   
   FileStream fs = new FileStream(
    file,
    FileMode.Open,
    FileAccess.Read,
    FileShare.Read);
       
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
 }
}
 
