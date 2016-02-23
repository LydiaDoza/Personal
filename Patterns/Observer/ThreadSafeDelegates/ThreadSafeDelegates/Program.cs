using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ThreadSafeDelegates
{
    class Program
    {
        public delegate void SomeEventHandler();

        public static void PrintADot()
        {
            Console.Write(".");
        }

        public class Subject
        {
            public SomeEventHandler handler;

            private void NullHandler()
            {
                Console.Write("*");
            }

            public Subject()
            {
                //handler += NullHandler;
            }

            public void Run()
            {
                SomeEventHandler localhandler;
                while (true)
                {
                    localhandler = handler;
                    if (localhandler != null)
                    {
                        localhandler();
                    }
                }
            }

        }
        static void Main(string[] args)
        {
            Subject subject = new Subject();
            Thread thread = new Thread(subject.Run);
            thread.Start();

            while (true)
            {
                subject.handler += PrintADot;
                subject.handler -= PrintADot;
            }

        }
    }
}
