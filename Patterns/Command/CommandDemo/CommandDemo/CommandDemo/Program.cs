using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CommandDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            ReminderService reminderService = new ReminderService();
            Console.WriteLine("The current time is: {0}", DateTime.Now);
            Console.WriteLine("Enter the alarm time");
            DateTime alarmTime = DateTime.Parse(Console.ReadLine());

            //IReminderStrategy strategy = new ConsoleReminderStrategy();
            //IReminderStrategy strategy = new MessageBoxReminderStrategy();
            // ICommand command = new MessageBoxCommand();
            string msg = "Don't forget the milk";
            Console.WriteLine("Enter wavefile");
            string wavefile = Console.ReadLine();

            ICommand command = new SoundCommand(wavefile, ConsoleColor.Green, msg);
            reminderService.AddReminder(alarmTime, command);

            Console.ReadLine();
        }
    }
}
