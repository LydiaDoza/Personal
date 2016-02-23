using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace HttpClient
{
    public class BandWidthDecorator: StreamDecorator
    {

        public BandWidthDecorator(Stream stream):base(stream)
        {

        }

        private Stopwatch timer;
        private long totalbytesread;
        public override int Read(byte[] buffer, int offset, int count)
        {
            if (timer == null)
            {
                timer = Stopwatch.StartNew();
            
            }
                  
            int bytesread =  base.Read(buffer, offset, count);

            totalbytesread += bytesread;

            Console.SetCursorPosition(0, 0);
            Console.WriteLine("Bandwidth {0} kb/s", 
                (double) totalbytesread / (double) timer.ElapsedMilliseconds);

            return bytesread;
        }
    }
}
