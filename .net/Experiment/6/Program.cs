using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment6
{
    class Program
    {
        static void Main(string[] args)
        {
            Heater heater = new Heater();
            AlarmSet alarm = new AlarmSet();
            LEDScreen screen = new LEDScreen();

            heater.Boiled += alarm.MakeBoiledAlert;
            heater.Boiled += screen.ShowBoiledMsg;

            heater.NearlyBoiled += alarm.MakeNearlyBoiledAlert;
            heater.NearlyBoiled += screen.ShowNearlyBoiledMsg;

            heater.Common += screen.ShowCommonMsg;

            heater.BoilWater();
        }
    }
}
