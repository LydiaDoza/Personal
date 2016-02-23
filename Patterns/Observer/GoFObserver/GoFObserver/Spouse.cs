using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoFObserver
{
    class Spouse : IStudentObserver
    {
        public void StartedWork()
        {
            Console.WriteLine("Glad you made it to school safely");
        }

        public void Working()
        {
            
        }

        public void FinishedWork()
        {
            Console.WriteLine("Hurry home dinner is ready");
        }
    }
}
