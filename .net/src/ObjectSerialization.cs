//ObjectSerialization.cs --对象/集合数据序列化与反序列化

//TestSerialization.cs
using System;
using System.Runtime.Serialization.Formatters.Binary;
//▼Student对象标记了[Serializable]:
//    可【序列化】
[Serializable] 
public class Student
{
    private int ID;
    private string name;
   
    public Student(int i, string s)
    {
        ID = i;
        name = s;
    }
   
    public override string ToString()
    {
        return "\n学号: " + ID + "\n姓名: " + name;
    }
} 
class BinaryWriteObject
{
    public static void Test()
    {
        Console.WriteLine("****Fun with Object Serialization****");   
       
        //TestWO();  //步骤一
        //TestRO();  //步骤二
       
        TestWRObjArr();
        //步骤三(每个元素依次写与读)
        //步骤四(整个数组作为整体写与读)   
    }
   
    static void TestWO() {
        Console.WriteLine("Writing object to binary file....");   
       
        //建立一个Student类对象
        Student s = new Student(101, "AAA李四光AAA");
       
        //将对象以二进制保存到文件student.dat中
        BinaryFormatter binFormat = new BinaryFormatter();
        Stream fs = new FileStream("student.dat", FileMode.Create,
                                    FileAccess.Write, FileShare.None);
        binFormat.Serialize(fs, s);
        fs.Close();
    }
   
    static void TestRO() {
        Console.WriteLine("Reading object from binary file....");
       
        //从二进制文件student.dat中把Student类对象读取到流中
        BinaryFormatter binFormat = new BinaryFormatter();
        //Stream fs = File.OpenRead("student.dat");
        //Student s = (Student)binFormat.Deserialize(fs);   
        //Console.WriteLine(s);
        //fs.Close();
       
       
        //★C#中的【using】关键字
        // 下面的代码保证当退出using作用域时，
        //  自动调用Dispose(): 亦即, fs会自动关闭■
    //  注意，其中的fs在{}中不能重新new赋值。
        using(Stream fs = File.OpenRead("student.dat")) {
            Student s = (Student)binFormat.Deserialize(fs);
            Console.WriteLine(s);
        }
    }
   
    static void Main() {
        Console.WriteLine("Writing many objects to binary file....");
        //建立一个Student对象数组
        Student[] stuArr = {
            new Student(101, "AAA 1 ZHU De AAA"),
            new Student(102, "AAA 2 Peng Dehuai AAA"),
            new Student(103, "AAA 3 LIN Biao AAA"),
            new Student(104, "AAA 4 LIU Bocheng AAA"),
            new Student(105, "AAA 5 HE Long AAA"),
            new Student(106, "AAA 6 CHEN Yi AAA"),
            new Student(107, "AAA 7 LUO Ronghuan AAA"),
            new Student(108, "AAA 8 XU Xiangqian AAA"),
            new Student(109, "AAA 9 LIE Rongzhen AAA"),
            new Student(110, "AAA 10 YE Jianying AAA")
        };
       
        //将对象数组全部以二进制保存到文件student.dat中
        BinaryFormatter binFormat = new BinaryFormatter();
        Stream fs = new FileStream("stu_arr.dat", FileMode.Create,
                                    FileAccess.Write, FileShare.None);
        //【方式①】把每个元素(对象)依次写进文件流
        //foreach(Student se in stuArr) {
        // binFormat.Serialize(fs, se);
        //}
       
        //【方式②】把对象数组写进文件流
        binFormat.Serialize(fs, stuArr);
       
        fs.Close();  //关闭文件流
       
        Console.WriteLine("Reading many objects from binary file....");
        //从二进制文件student.dat中读出所有对象
        fs = File.OpenRead("stu_arr.dat");  //重新打开刚被写进数据的文件
       
        //【方式①】试图挨个从文件流中读出每个对象
        /*Student s;
        try {
            while ((s = (Student)binFormat.Deserialize(fs)) != null) {
                Console.WriteLine(s);
            }
        } catch (Exception e) {
            Console.WriteLine(e.Message + "对象已经全部读取.");
        }*/
       
       
        //【方式②】从文件流中按Student对象数组读取
        Student[] sarr = (Student[])binFormat.Deserialize(fs);
        foreach(Student se  in sarr) {
            Console.WriteLine(se);
        }
       
        fs.Close();
    }
}
 
