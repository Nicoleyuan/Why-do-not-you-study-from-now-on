//Complex.cs   运算符重载
using System;
public class Complex {  //class or struct
  private double real;
  private double imaginary;
  public Complex(double r, double i) {
    real = r;
    imaginary = i;
  }
  public static Complex operator+(
          Complex c1, Complex c2) {
    return new Complex(c1.real + c2.real,
          c1.imaginary + c2.imaginary);
  }
  public double R {
    get { return real; }
    set { real = value; }
  }
  public double I {
    get { return imaginary; }
    set { imaginary = value; }
  }
  // 重写object类中的方法ToString
  public override string ToString() {
    return string.Format(" {0} + {1}i ",
       real, imaginary);
  }
 
  //Complex1.cs
  public static Complex operator-(
          Complex c1, Complex c2) {
    return new Complex(c1.R - c2.R, c1.I - c2.I);
  }
  public static Complex operator*(
          Complex c1, Complex c2)
  {
    return new Complex( c1.R*c2.R - c1.I*c2.I,
       c1.R*c2.I + c1.I*c2.R);
  }
  public static Complex operator/(
          Complex c1, Complex c2)
  {
    return new Complex(
      (c1.R*c2.R + c1.I*c2.I)/
      (c2.R*c2.R + c2.I*c2.I),
      (c2.R*c1.I - c2.I*c1.R)/
      (c2.R*c2.R + c2.I*c2.I));
  }
 
  //warning: “Complex”定义运算符 == 或运算符 !=，
  //    但不重写 Object.Equals(object o)
  //warning: “Complex”定义运算符 == 或运算符 !=，
  //    但不重写 Object.GetHashCode()
  //重载关系运算符
  //1 重写object类中的方法Equals 
  public override bool Equals(object obj)
  {
    Console.WriteLine("public override bool Equals(object obj)");
    if(obj == null)
      return false;
    Complex c = obj as Complex;
    //▲as运算符：转换成功则返回对象引用
    //            转换失败则返回null
    if((object)c == null)
      return false;
    return (R == c.R) && (I == c.I);
  }/*
  public bool Equals(Complex c) {
    Console.WriteLine("public bool Equals(Complex c)");
    if((object)c == null) 
      return false;    //参数为null则返回false
    return (R == c.R) && (I == c.I);
  }*/
  //重写object类中的方法GetHashCode
  public override int GetHashCode()
  {
    return (int)R ^ (int)I;
  }/**/
  public static bool operator==(Complex a, Complex b)
  {
    //a,b同为null或是同一对象
    if(object.ReferenceEquals(a, b))
      return true;
    //上一条语句若没有返回true则表明a,b不可能同为null
    //▼比较a == null时，将 a 强制转换为object:
    //         以避免无限递归。
    if((object)a == null || (object)b == null)
      return false; //只有一个null，不可能相同
    return a.R == b.R && a.I == b.I;
  }
  public static bool operator!=(Complex a, Complex b)
  {
    return !(a == b);
  }
}
public class TestComplex {
  static void Main(){
    Complex c1 = new Complex(3, 4);
    Complex c2 = new Complex(1, 2);
    //c2 += c1;  // c2 = c2 + c1;
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;
    Complex quotation = c1 / c2;
   
    Console.WriteLine("c1 = {0}", c1);
    Console.WriteLine("c2 = {0}", c2);
    Console.WriteLine("sum = {0}", sum);
    Console.WriteLine("diff = {0}", diff);   
    Console.WriteLine("product = {0}", product);
    Console.WriteLine("quotation = {0}", quotation);
   
    Console.WriteLine("c1 == c2: {0}", c1 == c2);
    Console.WriteLine("c1 != c2: {0}", c1 != c2);
    Complex c3 = new Complex(3, 4);
    Console.WriteLine("c1 == c3: {0}", c1 == c3);
    Console.WriteLine("c1 != c3: {0}", c1 != c3);
    Console.WriteLine("c1.Equals(c3): {0}",
                       c1.Equals(c3));
   
  }
}
 
