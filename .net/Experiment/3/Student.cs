using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment3
{
    class Student
    {
        private int sno = 0;
        private string sname = "";
        private string major = "";
        private Course[] courses;
        private readonly int num ;
       // private Student[] arrstu;
        
        public Student(int sno,string sname,string major,Course[] courses)
        {
            this.sno = sno;
            this.sname = sname;
            this.major = major;
            this.courses = courses;
            num = courses.Length;
            //arrstu = new Student[num];

         }
        public int Sno
        {
            get
            {
                return sno;
            }
            set
            {
                sno = value;
            }
        }
        public string Sname
        {
            get
            {
                return sname;
            }
            set
            {
                sname = value;
            }
        }
        public string Major
        {
            get
            {
                return major;
            }
            set
            {
                major = value;
            }
        }

        public override string ToString()
        {
            return String.Format("学号：{0,-8}\t姓名：{1,-8}\t专业：{2,-8}\n选修课程：\n",sno,sname,major);
        }

        public Course this[int index]//定义索引器,用于设置和读取学生的课程
        {
            get
            {
                if (index >= 0 && index < num)
                    return courses[index] ;
                else
                {
                    Console.WriteLine("您访问的学生已越界！");
                    return null;
                }
            }
            set
            {
                if (index >= 0 && index < num)
                    courses[index] = value;
                else
                {
                    Console.WriteLine("越界！");
                }

            }
        }

        public string this[string cno]//重载索引器，用于读取学生的课程
        {
            get
            {//找到有学生选的课程号
                for(int i = 0;i < num;i++)
                {
                    if (cno.Equals(courses[i].Cno)) return courses[i].ToString();
                    
                }
                
                return "查无此课程";
            }
            set
            {
                //无设置
            }
        }
    }
}
