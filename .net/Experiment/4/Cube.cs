using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment4
{
    class Cube:IArea,IVolume
    {
        public double SizeLength = 0;

        public double Sizelength
        {
            get { return SizeLength; }
            set { SizeLength = value; }
        }
        void IArea.Area()
        {
            double area = SizeLength * SizeLength * 6;
            Console.WriteLine("边长为{0}的立方体表面积是：{1}.", SizeLength, area);
        }
        void IVolume.Volume()
        {
            double volume = Math.Pow(SizeLength, 3);
            Console.WriteLine("边长为{0}的立方体体积是{1}.", SizeLength, volume);
        }

    }
}
