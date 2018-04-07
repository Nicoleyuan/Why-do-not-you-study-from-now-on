using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment2
{
    class Program
    {
        static void Main(string[] args)
        {
            Student s1 = new Student(1);
            Student s2 = new Student(2, "zsy", 18);
            Student s3 = new Student(3, "zhang", 18, "Software Engineering", "201509", "top_class");
            Console.WriteLine(s1.ToString());
            Console.WriteLine(s2.ToString());
            Console.WriteLine(s3.ToString());

            MethodParameter m1 = new MethodParameter();
            double result = 0;
            m1.sum(out result, 95, 4, 17);
            double[] b = MethodParameter.Order(8, 2, 4);
            for (int i = 0; i < 3; i++)
                Console.WriteLine(b[i]);
            Console.WriteLine(result);
            Console.ReadLine();
        }
    }
}
