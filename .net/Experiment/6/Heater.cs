using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Experiment6
{
    class Heater
    {
        private int temperature = 0;

        public delegate void BoiledEventHandler(Object sender, int t);

        public event BoiledEventHandler Boiled;
        public event BoiledEventHandler NearlyBoiled;
        public event BoiledEventHandler Common;

        private void OnBoiled(int t)
        {
            if (Boiled != null)
            {
                Boiled(this, t);
            }
        }

        private void OnNearlyBoiled(int t)
        {
            if (NearlyBoiled != null)
            {
                NearlyBoiled(this, t);
            }
        }

        private void OnCommon(int t)
        {
            if (Common != null)
            {
                Common(this, t);
            }
        }

        public void BoilWater()
        {
            temperature = 0;
            while (true)
            {
                if (temperature < 100)
                {
                    temperature++;
                }
                if (temperature >= 60 && temperature < 100)
                {
                    OnNearlyBoiled(temperature);
                }
                else if (temperature == 100)
                {
                    OnBoiled(temperature);
                }
                else
                {
                    OnCommon(temperature);
                }
                Thread.Sleep(1000);
            }
        }
    }
}
