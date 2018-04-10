using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment3
{
    class A
    {
        int i;
        public override string ToString()
        {
            return string.Format("An A object of i={0}.", i);
        }
        /*public static void Main()
        {
            A a ; //(3)A a; 或 (4) A a = null;
            a.i = 2;
            Console.WriteLine(a);
            Console.ReadLine();

        }*/
    }


}
