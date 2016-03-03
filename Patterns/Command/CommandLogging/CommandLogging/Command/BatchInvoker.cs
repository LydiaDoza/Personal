using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Command
{
    public class BatchInvoker
    {
        private List<ICommand> _commands = new List<ICommand>();

        public void Execute(ICommand command)
        {
            _commands.Add(command);

            if (_commands.Count == 5)
            {
                foreach (ICommand cmd in _commands)
                    cmd.Execute();

                _commands.Clear();
                Thread.Sleep(500);
            }
        }
    }
}
