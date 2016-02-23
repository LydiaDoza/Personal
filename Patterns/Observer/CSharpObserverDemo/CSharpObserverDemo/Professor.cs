using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpObserverDemo
{
    class Professor : IDisposable
    {
        Student _student;

        public Professor(Student student)
        {
            _student = student;
            _student.startedWork += StartedWork;
            _student.working += Working;
            _student.finishedWorking += FinishedWorking;
        }

        public void StartedWork()
        {
            Console.WriteLine("About Time");
        }

        public void Working()
        {
            Console.WriteLine("Work Harder");
        }

        public void FinishedWorking()
        {
            Console.WriteLine("Find something else to do");
        }

        public void Dispose()
        {
            _student.startedWork -= StartedWork;
            _student.working -= Working;
            _student.finishedWorking -= FinishedWorking;
        }
    }
}
