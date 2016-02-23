using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace CSharpObserverDemo
{
    class Student
    {
        public  StartedWork startedWork;
        public event Working working;
        public event FinishedWorking finishedWorking;

        public Student()
        {
            startedWork += NullHandler;
            working += NullHandler;
            finishedWorking += NullHandler;
        }
        public void NullHandler()
        { }

        public void DoWork()
        {
            startedWork();

            for (int i = 0; i < 10; i++)
            {
                working();
                Thread.Sleep(100);
            }

            finishedWorking();
        }
    }
}
