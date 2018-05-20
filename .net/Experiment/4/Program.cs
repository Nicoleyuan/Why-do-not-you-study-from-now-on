using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment4
{
    class Program
    {
        static void Main(string[] args)
        {
            IArea a1 = new Circle();  //Circle类不用实现接口IVolume
            IArea a2 = new Cube();
            ((Circle)a1).R = 2;
            ((Cube)a2).SizeLength = 2;
            a1.Area();
            a2.Area();
            ((IVolume)a2).Volume();
            Console.ReadLine();
        }
    }
}
