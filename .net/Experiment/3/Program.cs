using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment3
{
    class Program
    {
       
        static void Main(string[] args)
        {
            Course[] courses = new Course[5];
            Student stu = new Student(1, "a", "软件", courses);

            stu[0] = new Course("00001", "C#", "3分");
            stu[1] = new Course("00002", "C++", "3分");
            stu[2] = new Course("00003", "C语言", "3分");
            stu[3] = new Course("00004", "数据结构", "4分");
            stu[4] = new Course("00005", "高等数学", "4分");
            //stu[5] = new Course("00006", "大学英语", "2.5分");
            foreach(Course c in courses)
            {
                Console.WriteLine(c.ToString());
            }

            Console.WriteLine(stu["00006"]);
            Console.WriteLine(stu["00004"]);


            Console.ReadLine();


            /*Student[] stu = new Student[5];
            //Student stu = new Student();
            stu[0].Sno = 1;
            stu[0].Sname = "a";
            stu[0].Sname = "软件";
            stu[1] = new Student(2, "b", "软件", courses);
            stu[2] = new Student(3, "c", "软件", courses);
            stu[3] = new Student(4, "d", "软件", courses);
            stu[4] = new Student(5, "e", "软件", courses);
            stu[5] = new Student(5, "e", "软件", courses);//越界*/




        }
    }
 }

