using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace CommandDemo
{
    class ReminderService
    {
        public void AddReminder(DateTime alarmTime, ICommand command)
        {
            TimeSpan deltaTime = alarmTime - DateTime.Now;

            //Timer reminderTimer = new Timer(delegate { Console.WriteLine(alarmTime); }, null,
            //    deltaTime, new TimeSpan(-1));
            Timer reminderTimer = new Timer(delegate { command.Execute(); }, null,
                deltaTime, new TimeSpan(-1));

        }
    }
}
