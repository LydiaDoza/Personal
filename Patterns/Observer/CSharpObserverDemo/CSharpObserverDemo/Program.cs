using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpObserverDemo
{
    public delegate void StartedWork();
    public delegate void Working();
    public delegate void FinishedWorking();
    class Program
    {
        static void Main(string[] args)
        {
            Student Jim = new Student();
            using (Professor Breedlove = new Professor(Jim))
            using (Spouse Sally = new Spouse(Jim))
            {
                Jim.DoWork();
                //Jim.finishedWorking();
            }

        }
    }
}
