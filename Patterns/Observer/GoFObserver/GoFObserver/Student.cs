using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace GoFObserver
{
    class Student
    {
        List<IStudentObserver> observers = new List<IStudentObserver>();

        public void Attach(IStudentObserver observer)
        {
            observers.Add(observer);
        }

        public void Detach(IStudentObserver observer)
        {
            observers.Remove(observer);
        }

        public void DoWork()
        {
            foreach (IStudentObserver observer in observers)
            {
                observer.StartedWork();

                for (int i = 0; i < 10; i++)
                {
                    observer.Working();
                    Thread.Sleep(100);
                }

                observer.FinishedWork();
            }
        }
    }
}
