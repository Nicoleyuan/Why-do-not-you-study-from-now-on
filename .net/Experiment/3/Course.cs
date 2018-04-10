using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment3
{
    class Course
    {
        private string cno = "";
        private string cname = "";
        private string credit = "";

        public Course(string cno,string cname,string credit)
        {
            this.cno = cno;
            this.cname = cname;
            this.credit = credit;
        }
        public string Cno
        {
            get { return cno; }
            set { cno = value; }
        }
        public override string ToString()
        {
            return String.Format("课程号：{0,-8}\n课程名：{1,-8}\n学分：{2,-8}\n",cno,cname,credit);
        }
    }
}
