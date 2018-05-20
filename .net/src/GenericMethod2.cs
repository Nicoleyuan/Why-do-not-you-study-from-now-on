//GenericMethod2.cs  泛型方法, 对象的排序：System.IComparable接口，System.Collections.IComparer接口的实现
using System;
class Student : IComparable {
 private int id;
 private string name;
 //private int gpa;
 public double GPA {set; get; } //自动Property
 
 public Student(int id, string name, double gpa) {
  this.id = id;
  this.name = name;
  GPA = gpa; //通过GPA set隐含的字段
 }
 //public int CompareTo(object obj) {
 int IComparable.CompareTo(object obj) {
  Student s = (Student)obj;
  return this.name.CompareTo(s.name);
 }
 
 public override string ToString() {
  return string.Format("学号:{0,4}  姓名:{1,3} GPA: {2,2}\n",
    id, name, GPA);
 }
}
//* // 自定义比较器类
public class StudentComparer
                : System.Collections.IComparer {
 public int Compare(object s1, object s2) {
  return (((Student)s1).GPA).CompareTo(((Student)s2).GPA);
 }
}//*/
public class GenericMethod2 {
 static void Main() {
  int[] a = {1, 2, 3, 4, 5, 6};
  Student[] b = new Student[7];
  b[0] = new Student(101, "伊尹", 3.95);
  b[1] = new Student(102, "管仲", 4.28);
  b[2] = new Student(103, "吴起", 4.95);
  b[3] = new Student(104, "孙武", 3.99);
  b[4] = new Student(105, "白起", 4.28);
  b[5] = new Student(106, "王翦", 4.3);
  b[6] = new Student(107, "孙武", 4.7);
  Console.WriteLine("======== 一开始 ========");
  Display(a);
  Display<Student>(b);
  
  Console.WriteLine("======== ’Array.Sort(b, 2, 4);’ called ========");
  Array.Sort(b, 2, 4);
  Display(b);
  //使用比较器StudentComparer来排序
  Console.WriteLine("======== ’Array.Sort(b, 0, 7, new StudentComparer());’ called ========");
  Array.Sort(b, 0, 7, new StudentComparer());
  Display(b);
  
  Console.WriteLine("======== ’Array.Clear(b,1,3);’ called ========");
  Array.Clear(b,1,3);
  Display(b);
  
  Console.ReadKey();
 }
 
 static void Display<T>(T[] arr) //where T : struct //class
 {
  Console.WriteLine("============================");
  foreach(T e in arr)
  {
   if(e == null)
     Console.WriteLine();
   else
      Console.Write("{0, 6}", e);
   }
   
  Console.WriteLine();
 }
}
