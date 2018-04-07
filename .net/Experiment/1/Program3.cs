using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            //int a;
           // Console.Write("是否进入简单四则运算？");
            //Console.Write("提示：1.yes  2.no\n");
            //a = Convert.ToInt32(Console.ReadLine());
            while (true)
            {
                int x;
                int y;
                int z;
                Console.Write("请输入第一个数字：");
                x = Convert.ToInt32(Console.ReadLine());
                Console.Write("请输入第二个数字：");
                y = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("请选择操作符");
                Console.WriteLine("1. 加");
                Console.WriteLine("2. 减");
                Console.WriteLine("3. 乘");
                Console.WriteLine("4. 除");
                Console.WriteLine("任意其他键退出");
                String s = Console.ReadLine();
                z = Convert.ToInt32(s);
                if (!s.Equals("1") && !s.Equals("2") && !s.Equals("3") && !s.Equals("4")) break;
                switch (z)
                {
                    case 1:
                        add(x, y);
                        break;
                    case 2:
                        sub(x, y);
                        break;
                    case 3:
                        mul(x, y);
                        break;
                    case 4:
                        div(x, y);
                        break;
                    default:
                        Console.Write("请输入正确的序号！");
                        Console.ReadLine();
                        break;
                }
                Console.ReadLine();
            }
         }

        static void add(int x,int y)
        {
            Console.WriteLine("{0}+{1}={2}", x, y, x + y);
        }

        static void sub(int x, int y)
        {
            Console.WriteLine("{0}-{1}={2}", x, y, x - y);
        }

        static void mul(int x, int y)
        {
            Console.WriteLine("{0}*{1}={2}", x, y, x * y);
        }

        static void div(int x, int y)
        {
            try
            {
                Console.WriteLine("{0}/{1}={2}", x, y, x / y);
            }
            catch(DivideByZeroException ex)
            {
                Console.WriteLine("输入有误,除数不可为0！"+ex.Message);
            }
        }
    }
}
