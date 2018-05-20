using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment4
{
    class Circle:IVolume,IArea
    {
        public double R = 0;
        public double _R
        {
            get { return R; }
            set { R = value; }
        }
        void IArea.Area()
        {
            double area = Math.Pow(R, 2) * Math.PI;
            Console.WriteLine("半径为{0}的圆的面积是：{1}.", R, area);
        }
        void IVolume.Volume()
        {
            Console.WriteLine("圆的体积：N/A.");
        }
    }
}
