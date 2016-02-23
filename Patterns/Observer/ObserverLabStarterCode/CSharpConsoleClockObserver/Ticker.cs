using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace CSharpConsoleClockObserver
{
    public delegate void OnSecondsDelegate();
    public delegate void OnTenthsDelegate();
    public delegate void OnHundredthsDelegate();

    public class Ticker
    {
        public event OnSecondsDelegate OnSecondsTick;
        public event OnTenthsDelegate OnTenthsTick;
        public event OnHundredthsDelegate OnHundredthsTick;


        private bool done;
        

        /// <summary>
        /// Wow! Such nullhandler. 
        /// </summary>
        public void NullHandler() { }

        public bool Done
        {
            get { return done; }
            set { done = value; }
        }

   
        public void Run()
        {
            int count = 0;
            while (!done)
            {
                Interlocked.Increment(ref count);
                OnHundredthsTick();
                OnSecondsTick();
                OnTenthsTick();


                if (count % 36000 == 0)
                {
                    count = 0;
                }
            }
        }

        
    }
}
