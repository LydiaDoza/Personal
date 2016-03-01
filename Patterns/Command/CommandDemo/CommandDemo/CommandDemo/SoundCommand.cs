using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Media;

namespace CommandDemo
{
    class SoundCommand : ICommand
    {
        string _wavFile;
        ConsoleColor _color;
        string _msg;

        public SoundCommand(string waveFile, ConsoleColor color, string msg)
        {
            _wavFile = waveFile;
            _color = color;
            _msg = msg;
        }
        public void Execute()
        {
            SoundPlayer player = new SoundPlayer(string.Format(@"c:\windows\media\{0}.wav", _wavFile));
            Console.ForegroundColor = _color;
            Console.WriteLine(_msg);
            player.Play();
            Console.ResetColor();
        }
    }
}
