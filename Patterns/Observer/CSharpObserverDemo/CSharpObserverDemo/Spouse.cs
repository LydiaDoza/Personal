using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpObserverDemo
{
    class Spouse : IDisposable
    {
        Student _student;

        public Spouse(Student student)
        {
            _student = student;
            _student.startedWork += StartedWork;
            _student.finishedWorking += FinishedWorking;
        }

        public void StartedWork()
        {
            Console.WriteLine("Glad you made it to school safely");
        }

        public void FinishedWorking()
        {
            Console.WriteLine("Hurry home dinner is ready");
        }

        public void Dispose()
        {
            _student.startedWork -= StartedWork;
            _student.finishedWorking -= FinishedWorking;
        }

        //public int Add(int x, int y)
        //{
        //    return x + y;
        //}
    }
}
