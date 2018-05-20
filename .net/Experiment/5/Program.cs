using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Experiment5
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack pail = new Stack(10);
            /*Thread pro1 = new Thread(pail.Push);
            pro1.Name = "师傅1";
            pro1.Start("葱油饼");*/
            for (int i = 0; i < 20; i++)
            {
                Thread th = new Thread(pail.Push);
                th.Start("葱油饼");
                Thread th1 = new Thread(pail.Pop);
                th1.Start();
            }
            Console.ReadLine();

        }
    }
}
