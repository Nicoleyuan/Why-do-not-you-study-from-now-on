//TestIDisposable.cs 对象资源的释放；析构函数；GC.SuppressFinalize(obj) ； IDisposable接口与Dispose方法；using语句块

using System;
class Resource : IDisposable {
 public int Data;
 public Resource(int k) {
  Data = k;
 }
 ~Resource() {
  //base.Finalize();  //ERROR: 不要直接调用基类的Finalize方法,
                      //       它会从析构函数中自动调用。
  Console.WriteLine("~Resource() called for Resource({0})", Data);
 }
 public void print() {
  Console.WriteLine(Data + " ");
 }
 
 //protected override void Finalize() {  //ERROR: 不要重写
 // base.Finalize();
 // Console.WriteLine("Finalize() called for Resource({0})", Data);
 //}
 
 //▼▼参考MSDN--System.GC.SuppressFinalize 方法
 //                        (GC类的静态方法)
 public void Dispose()
 {
  //GC.SuppressFinalize(this);  //★注释掉或取消注释试一试
  //▲▲对象变为不可访问后将自动调用此方法，
  //     除非已通过 SuppressFinalize 调用使对象免除了终结。■
  
  Console.WriteLine("Dispose() called for Resource({0})", Data);
  //throw new NotImplementedException();
 }
}
public class TestMy {
 public static void Main() {
  Resource res = new Resource(-1);  
  //Resource[] list= new Resource[20];
  //for(int i = 0;i<20;i++){
  // list[i] = new Resource(i);
  // Console.WriteLine("data="+list[i].Data);
  //}
  new TestMy().Tex(res);
  //
  //for(int i = 0;i<20;i++){
  // list[i].Dispose();  //★注释掉或取消注释掉试一试
  //}
 }
 public void Tex(object param) {
  Resource r0 = new Resource(100);
  
  using( Resource r1 = new Resource(111)) {
   r1.print();
   
   //r1 = new Resource(100);  //r1 为using变量，无法为它赋值
    //r1 = r0; //r1 为using变量，无法为它赋值
  }  //退出using块时，会自动调用 r1.Dispose()!
 }
}
 
