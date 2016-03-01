using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CommandDemo
{
    class ConsoleReminderStrategy : IReminderStrategy
    {
        public void Reminder()
        {
            Console.WriteLine("Wake up!!");
        }
    }
}
