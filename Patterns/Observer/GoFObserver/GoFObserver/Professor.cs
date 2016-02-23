using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoFObserver
{
    class Professor : IStudentObserver
    {
        public void StartedWork()
        {
            Console.WriteLine("About time");
        }

        public void Working()
        {
            Console.WriteLine("Work Harder!");
        }

        public void FinishedWork()
        {
            Console.WriteLine("Find something else to do!");
        }
    }
}
