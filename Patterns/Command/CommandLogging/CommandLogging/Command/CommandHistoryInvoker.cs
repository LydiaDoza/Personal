using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Command
{
    public class CommandHistoryInvoker
    {
        private string historyFile;

        public CommandHistoryInvoker(string historyFile)
        {
            this.historyFile = historyFile;
        }

        public void Execute(ICommand command)
        {
            command.Execute();

            LogCommandToDisk(command);
        }

        // Called when a complete save has
        // been succesful
        public void ClearHistory()
        {
            if (File.Exists(historyFile))
            {
                File.Delete(historyFile);
            }
        }

        public void Restore()
        {
            if (File.Exists(historyFile))//haven't just done a save and deleted file
            {
                BinaryFormatter formatter = new BinaryFormatter();

                using (Stream stream = File.OpenRead(historyFile))
                {
                    while (stream.Position < stream.Length)
                    {
                        ICommand cmd = (ICommand)formatter.Deserialize(stream);

                        cmd.Execute();
                    }
                }
            }
        }

        private void LogCommandToDisk(ICommand command)
        {
            BinaryFormatter formatter = new BinaryFormatter();

            using (Stream stream = File.OpenWrite(historyFile))
            {
                // Move to end of the history file
                stream.Seek(0, SeekOrigin.End);

                formatter.Serialize(stream, command);
            }
        }
    }
}
