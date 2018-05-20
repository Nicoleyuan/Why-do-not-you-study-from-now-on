using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment6
{
    class LEDScreen
    {
        public void ShowCommonMsg(Object sender, int t)
        {
            Console.WriteLine("LED屏显示：水温是 {0}, 请耐心等候.", t);
        }
        public void ShowNearlyBoiledMsg(Object sender, int t)
        {
            if (t >= 95)
            {
                Console.WriteLine("LED屏显示：水温是 {0}, 马上要烧开啦！", t);
            }
            else
            {
                ShowCommonMsg(sender, t);
            }
        }
        public void ShowBoiledMsg(Object sender, int t)
        {
            Console.WriteLine("LED屏显示：水温是 {0}, 已经烧开啦！", t);
        }
    }
}
