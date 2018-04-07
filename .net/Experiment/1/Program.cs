using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("请输入用户名：");
            string welcomeString = Console.ReadLine();
            Console.WriteLine("Welcome {0} ！", welcomeString);
            Console.ReadLine();
        }
    }
}
