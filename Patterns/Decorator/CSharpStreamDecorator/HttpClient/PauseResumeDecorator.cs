using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace HttpClient
{
    public class PauseResumeDecorator:StreamDecorator
    {

        public PauseResumeDecorator(Stream stream):base(stream)
        {

        }

        public override int Read(byte[] buffer, int offset, int count)
        {
           if (Console.KeyAvailable)
           {
               Console.WriteLine("Pause");
               if (Console.ReadKey().Key == ConsoleKey.P)
               {

                   while (Console.ReadKey().Key != ConsoleKey.R)
                   { }

                   Console.SetCursorPosition(0, 1);
                   Console.WriteLine("       ");
                   Console.SetCursorPosition(0, 2);
                   Console.WriteLine("     ");               
               }           
           }       
            
            return base.Read(buffer, offset, count);
        }
    }
}
