using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CommandDemo
{
    class MessageBoxCommand : ICommand
    {
        public void Execute()
        {
            System.Windows.Forms.MessageBox.Show("Wake up!");
        }
    }
}
