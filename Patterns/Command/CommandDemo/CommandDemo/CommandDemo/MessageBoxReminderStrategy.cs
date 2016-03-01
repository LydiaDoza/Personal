using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CommandDemo
{
    class MessageBoxReminderStrategy : IReminderStrategy
    {
        public void Reminder()
        {
            System.Windows.Forms.MessageBox.Show("Wake the heck up!");
        }
    }
}
