using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace GammaConsoleClockObserver
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.CursorVisible = false;

            SecondClock clock1 = new SecondClock(0, 1, ConsoleColor.Cyan);
            TenthSecondClock clock2 = new TenthSecondClock(0, 2, ConsoleColor.Green);
            HundredthSecondClock clock3 = new HundredthSecondClock(0, 3, ConsoleColor.Red);

            Ticker ticker = new Ticker();
            ticker.RegisterTimer(clock1);
            ticker.RegisterTimer(clock2);
            ticker.RegisterTimer(clock3);
            

            Thread thread = new Thread(ticker.Run);
            thread.Start();

            Console.ReadLine();

            ticker.Done = true;
            thread.Join();
        }
    }
}
