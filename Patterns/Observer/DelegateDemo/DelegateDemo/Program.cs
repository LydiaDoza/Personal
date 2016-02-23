using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateDemo
{
    class Program
    {
        //typedef (*FibDelegate)(int);
        delegate void FibDelegate(int current);

        private static void PrintFib(int current)
        {
            Console.WriteLine(current + 100);
        }

        private static void PrintColorFib(int current)
        {
            if (current % 2 == 0)
            {
                Console.ForegroundColor = ConsoleColor.Green;
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
            }
            Console.WriteLine(current);
        }

        private static void GenerateFib(int count, FibDelegate del)
        {
            int current = 1;
            int prev = 0;
            int prevprev = 0;
            for (int i = 0; i < count; i++)
            {
                //Console.WriteLine(current);
                if (del != null)
                {
                    del(current);
                }
                prevprev = prev;
                prev = current;
                current = prev + prevprev;
            }
        }
        static void Main(string[] args)
        {
            //GenerateFib(10);
            //GenerateFib(10, PrintFib);
            //GenerateFib(10, PrintColorFib);
            FibDelegate del = PrintFib;
            del += PrintColorFib;
            //del -= PrintColorFib;
            GenerateFib(10, del);

            //GenerateFib(10, delegate (int current) { Console.WriteLine(current); });

        }
    }
}
