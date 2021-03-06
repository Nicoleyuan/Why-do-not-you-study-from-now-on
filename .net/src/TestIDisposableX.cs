//TestIDisposableX.cs GC.SuppressFinalize(obj); IDisposable接口与Dispose()

using System;
class Resource : IDisposable {
 public int Data;
 public Resource(int k) {
  Data = k;
 }
 ~Resource() {
  Console.WriteLine("~Resource() called for Resource({0})", Data);
 }
 public void print() {
  Console.WriteLine(Data + " ");
 }
 
 //public void Dispose()  //实现接口IDisposable中的方法
 void IDisposable.Dispose()
 {
   //GC.SuppressFinalize(this); //〔1〕
  Console.WriteLine("Dispose() called for Resource({0})", Data);
 }
}
public class TestIDisposable {
 public static void Main() {
  Resource res = new Resource(-1);
  using(Resource r1 = new Resource(111)) {
    //GC.SuppressFinalize(r1);  //〔1〕
    r1.print();
  } //〔2〕退出using块时，会自动调用 r1.Dispose()!
  
  //res.Dispose(); //〔2〕 
  GC.SuppressFinalize(res);  //〔1〕
 }
}
