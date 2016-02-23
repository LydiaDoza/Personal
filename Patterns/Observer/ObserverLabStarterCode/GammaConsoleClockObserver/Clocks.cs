using System;
using System.Collections.Generic;
using System.Text;

namespace GammaConsoleClockObserver
{
    
    //Note: Shouldn't really have multiple classes in the same .cs file but I think
    //it drives home the point that interfaces cause you to implement all methods when
    //you can see all the classes together.
    
    public class SecondClock : Clock, ITimerObserver
    {
        public SecondClock(int originalColumn, int originalRow, ConsoleColor? color)
            : base(originalColumn, originalRow, color)
        {        }


        #region ITimer Members

        public void HundredthSecond()
        {        }

        public void TenthSecond()
        {        }

        public void Second()
        {
            DateTime dt = DateTime.Now;

            WriteAt(dt.Hour, 0, 0, 2);
            WriteAt(":", 2, 0);
            WriteAt(dt.Minute, 3, 0, 2);
            WriteAt(":", 5, 0);
            WriteAt(dt.Second, 6, 0, 2);
        }

        public void Minute()
        {        }

        public void Hour()
        {        }

        #endregion
    }

    public class HundredthSecondClock : Clock, ITimerObserver
    {
        public HundredthSecondClock(int originalColumn, int originalRow, ConsoleColor? color)
            : base(originalColumn, originalRow, color)
        {        }
        public void HundredthSecond()
        {
            DateTime dt = DateTime.Now;

            WriteAt(dt.Hour, 0, 0, 2);
            WriteAt(":", 2, 0);
            WriteAt(dt.Minute, 3, 0, 2);
            WriteAt(":", 5, 0);
            WriteAt(dt.Second, 6, 0, 2);
            WriteAt(".", 8, 0);
            WriteAt(dt.Millisecond / 10, 9, 0, 2);
        }

        public void TenthSecond()
        {        }

        public void Second()
        {        }

        public void Minute()
        {        }

        public void Hour()
        {        }
    }

    public class TenthSecondClock : Clock, ITimerObserver
    {
        public TenthSecondClock(int originalColumn, int originalRow, ConsoleColor? color)
            : base(originalColumn, originalRow, color)
        {        }
        public void HundredthSecond()
        {        }

        public void TenthSecond()
        {
            DateTime dt = DateTime.Now;

            WriteAt(dt.Hour, 0, 0, 2);
            WriteAt(":", 2, 0);
            WriteAt(dt.Minute, 3, 0, 2);
            WriteAt(":", 5, 0);
            WriteAt(dt.Second, 6, 0, 2);
            WriteAt(".", 8, 0);
            WriteAt(dt.Millisecond / 100, 9, 0, 1);
        }

        public void Second()
        {        }

        public void Minute()
        {        }

        public void Hour()
        {        }
    }
}
