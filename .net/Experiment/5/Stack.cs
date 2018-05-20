using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Experiment5
{
    class Stack
    {
        private int size = 10;
        private object[] StackSpace;
        private int top;

        public Stack(int size)
        {
            this.size = size;
            StackSpace = new object[size];
            top = -1;
        }
        public void Push(object c)
        {
            lock (this)
            {
                if (top == StackSpace.Length - 1)
                {
                    Console.WriteLine("桶已满！");
                }
                else
                {
                    StackSpace[++top] = c;
                    Console.WriteLine("葱油饼+1,共{0}个葱油饼",top+1);
                }
            }
            
        }
        public void Pop()
        {
            lock (this)
            {
                if (top == -1)
                {
                    Console.WriteLine("桶已空！");
                   // return Convert.ToChar(0);
                }
                else
                {
                    Console.WriteLine("葱油饼-1,共{0}个葱油饼", top);
                    top--;
                }
            }
        }

    }
}
