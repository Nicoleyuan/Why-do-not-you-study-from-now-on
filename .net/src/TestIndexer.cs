//TestIndexer.cs -- 索引器；Property与自动Property

using System;
using System.Collections.Generic;

namespace ByPoints.Indexer
{
  //第1个类：Student
  public class Student
  {
    //三个私有字段(属性)
    private int id;
    private string name;
    private int age;
    //另外有一个属性由编译器提供，被自动属性Political操纵
    //属性courses：放多门课程被该生修的课程的名字，
    //   后面提供索引器来操纵它
    private List<string> courses = new List<string>();
    //两个相互重载的构造函数:
    public Student(int id)
    {
      this.id = id;
    }
    public Student(int id, string name, int age)
    {
      this.id = id;
      this.name = name;
      this.age = age;
    }
    //三个操纵字段的Property
    //▼操纵字段id的只读Property: ID
    public int ID
    {
      get
      {
        return id;
      }
    }
    //▼操纵字段name的Property: Name
    public string Name
    {
      get
      {
        return name;
      }
      set
      {
        name = value;
      }
    }
    //▼操纵字段age的Property: Age
    public int Age
    {
      get
      {
        return age;
      }
      set
      {
        age = (value >= 12 && value <= 40) ? value : -1;
      } //-1是个醒目的非法值
    }
    //自动Property
    public string Political
    { //编译器自动维护有关字段
      set;
      get;
    }
    //索引器
    public string this[int index]
    {
      set
      {
        if (index > courses.Count + 1 || index < 0)
        {
          Console.WriteLine("设置学生 {0} 的课程时位置超出范围！", name);
        }
        else if (index == courses.Count + 1)
        {
          courses.Add(value);
        }
        else
        {
          courses.Insert(index, value);
        }
      }
      get
      {
        if (index >= courses.Count + 1 || index < 0)
        {
          Console.WriteLine("访问学生{0}的课程时位置超出范围！", name);
          return "N/A";
        }
        else
        {
          return courses[index];
        }
      }
    }
    //需要将对象当作字符串使用的场合，
    //  会（自动）调用对象.ToString()
    public override string ToString()
    {
      String s = string.Format(
             "========  ID:{0,3}  Name:{1,2}  Age:{2,2}  Political:{3}  ========\n",
             id, name, age, Political);
      s += "{";
      foreach (string c in courses)
      {
        s += string.Format(" {0} ", c);
      }
      s += "}\n";
      return s;
    }
  }
  //第2个类：Class
  public class Class
  {  //班级类
    //只读字段 numberOfStudents：准备在构造函数中赋值
    private readonly int numberOfStudents;
    //字段 students: 存放班级中同学信息，索引器访问其中的元素
    private Student[] students;
    //构造函数
    public Class(Student[] stuArray)
    {
      //数组对象Length Property:存放元素个数
      students = stuArray;
      numberOfStudents = students.Length;  //为只读字段赋值
    }
    //只读Property，访问学生个数
    public int NumberOfStudents
    {
      get
      {
        return numberOfStudents;
      }
    }
    //【索引器】: 访问班级中的学生
    public Student this[int index]
    {
      get
      {
        if (index >= 0 && index < numberOfStudents)
          return students[index];
        else
        {
          Console.WriteLine("Error:您要访问的学生索引超出范围");
          return null;
        }
      }
      set
      {
        if (index >= 0 && index < numberOfStudents)
          students[index] = value;
        else
        {
          Console.WriteLine("Error:设置学生 {0} 时索引超出范围",
                             value.Name); //((Student)value).Name);
        }
      }
    } //索引器定义结束 
    public override string ToString()
    {
      string classStudents = "";
      for (int i = 0; i < numberOfStudents; i++)
        classStudents += this[i];  // += this[i].ToString();
      return classStudents;
    }
  }
  //第3个类：TestIndexer
  public class TestIndexer
  {
    public static void Test()
    {
      Student[] stuArr = new Student[8];
      Class cc = new Class(stuArr);
      //访问索引器
      cc[0] = new Student(101); //索引器:set
      cc[0].Name = "伊尹";      //索引器:get 及 Property:set
      cc[0].Age = 23;           //索引器:get 及 Property:set
      cc[1] = new Student(102, "比干", 19); //索引器:set
      cc[2] = new Student(103, "曹操", 23); //索引器:set
      cc[3] = new Student(104, "夫差", 22); //索引器:set
      cc[4] = new Student(105, "管仲", 19); //索引器:set
      cc[5] = new Student(106, "吴起", 17); //索引器:set
      cc[6] = new Student(107, "孙权", 22); //索引器:set
      cc[7] = new Student(108, "颜渊", 21); //索引器:set
      cc[8] = new Student(109, "赵括", 23); //索引器:set--发现越界
      cc[5].Political = "党员";
      cc[5][0] = "高等数学";
      cc[5][1] = "离散数学";
      cc[5][2] = "大学英语I";
      cc[5][3] = "数据结构";
      cc[5][9] = "SQL Server数据库应用";
      Console.WriteLine(cc);  //cc.ToString()
      for (int i = 0; i < cc.NumberOfStudents; i++)
      {
        //Console.Write(cc[i]); //①索引器:get; ②Student对象.ToString()
        Console.Write("{0,4}", cc[i].Name); //索引器:get 及 Property:get
      }
      Console.WriteLine();
    }
  }
}
