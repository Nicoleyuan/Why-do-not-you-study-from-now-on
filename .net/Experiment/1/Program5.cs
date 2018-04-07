using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int startWeekDay, days;
            while (true)
            {
                Console.Write("该月第一天是星期几（1-7）?  ");
                startWeekDay = int.Parse(Console.ReadLine());
                if (startWeekDay < 1 || startWeekDay > 7)
                {
                    Console.Write("输入错误：数字不在1-7之间！");
                    Console.ReadLine();
                    Console.Clear();
                }
                else
                {
                    Console.Write("该月的天数（28-31）?  ");
                    days = int.Parse(Console.ReadLine());
                    if (days < 28 || days > 31)
                    {
                        Console.Write("输入错误：天数不在28-31之间！");
                        Console.ReadLine();
                        Console.Clear();
                    }
                    else
                        break;
                }
            }
            printMonCalendar(startWeekDay, days);

        }
        public static void printMonCalendar(int startWeekDay, int days)
        {
            // 
            List<string> dataes = new List<string>();
            int space = startWeekDay - 1;
            for (int i = 0; i < space; i++)
            {
                dataes.Add("");
            }
            for (int i = 1; i <= days; i++)
            {
                dataes.Add(i.ToString());
            }
            Console.Write("\n打印该月月历如下：\n");
            Console.WriteLine("------------------------------------------------------");
            Console.Write("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT");
            for (int i = 0; i < dataes.Count; i++)
            {
                if (i % 7 == 0)
                    Console.WriteLine();
                Console.Write(dataes[i] + "\t");
            }
            Console.WriteLine();
            Console.WriteLine("------------------------------------------------------");
            Console.Write("按回车键退出");
            Console.ReadLine();
            Console.Clear();

        }
    }
}
