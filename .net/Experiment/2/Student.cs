using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment2
{
    class Student
    {
        readonly static int studentNum = 0; //代表当前已经产生的Student的对象的个数
        private readonly int sno; //要求调用构造函数创建Student对象以后，sno不允许修改
        private string sname = "";
        private int age = 0;
        private string major = "";
        private string entryYearMon = "";
        private string politicalStatus = "";

        public Student(int sno)
        { this.sno = sno; }
        public Student (int sno,string sname,int age)
        {
            this.sno = sno;
            this.sname = sname;
            this.age = age;
        }
        public Student(int sno, string sname, int age, string major, string entryYearMon, string politicalStatus):this(sno,sname,age)
        {
            this.major = major;
            this.entryYearMon = entryYearMon;
            this.politicalStatus = politicalStatus;
        }

        public int StudentNum
        {
            get { return studentNum; }
        }
        public int SNO
        {
            get { return sno; }
        }
        public string SName
        {
            get { return sname; }
            set { sname = value; }
        }
        public int Age
        {
            get { return age; }
            set { age = value; }
        }
        public string Major
        {
            get { return major; }
            set { major = value; }
        }
        public string EntryYearMon
        {
            get { return entryYearMon; }
            set { entryYearMon = value; }
        }
        public string PoliticalStatus
        {
            get { return politicalStatus; }
            set { politicalStatus = value; }
        }

        //重写ToString方法，方便对Studet对象以字符串方式输出
        public override string ToString()
        {
            return String.Format("学号：{0,-10}\n姓名：{1,-10}\n年龄：{2,-8}\n专业：{3,-10}\n入学年月：{4,-8}\n政治面貌：{5,-10}\n",
                sno,
                sname == "" ? "N/A" : sname,
                age.ToString() == "0" ? "N/A" : age.ToString(),
                major == "" ? "N/A" : major,
                entryYearMon == "" ? "N/A" : entryYearMon,
                politicalStatus == "" ? "N/A" : politicalStatus
                );
        }
    }
}
