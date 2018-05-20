using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment6
{
    class AlarmSet
    {
        public void MakeNearlyBoiledAlert(Object sender, int t)
        {
            Console.WriteLine("报警音提示：嗡~~嗡~~嗡~~嗡~~嗡~~嗡~~");
        }
        public void MakeBoiledAlert(Object sender, int t)
        {
            Console.WriteLine("报警音提示：滴~~滴~~滴~~滴~~滴~~滴~~");
        }
    }
}
