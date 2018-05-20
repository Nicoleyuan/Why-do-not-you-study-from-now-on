using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment4
{
     class Shape:IArea,IVolume
    {
        void IArea.Area()
        {
            Console.WriteLine("调用了IArea的Area()");
        }
        void IVolume.Volume()
        {
            Console.WriteLine("调用了IVolume的IVolume()");
        }
        /* public virtual void Area()
         {
             Console.WriteLine("调用了虚方法Area()");
         }
         public virtual void Volume()
         {
             Console.WriteLine("调用了虚方法Volume()");
         }*/

    }
}
