using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment2
{
    class MethodParameter
    {
        public static double[] Order(double a, double b, double c)
        {
            double[] order = new double[3];
            if (a > b)
            {
                if (a > c)
                {
                    order[0] = a;
                    order[1] = b >= c ? b : c;
                    order[2] = (order[1] == b) ? c : b;
                }
                else { order[0] = c; order[1] = a; order[2] = b; }
            }
            else if (b > c)
            {
                order[0] = b;
                order[1] = a > c ? a : c;
                order[2] = (order[1] == a ? c : a);
            }
            else
            {
                order[0] = c;
                order[1] = b;
                order[2] = a;
            }

            return order;
        }

        public void sum(out double result, params double[] array)
        {
            result = 0;
            for (int i = 0; i < array.Length; i++)
            {
                result += array[i];
            }
        }
    }
}
