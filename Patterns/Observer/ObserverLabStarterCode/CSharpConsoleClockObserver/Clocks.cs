using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpConsoleClockObserver
{
    public class SecondClock : Clock, IDisposable
    {
        private Ticker _ticker;
        public SecondClock(int originalColumn, int originalRow, ConsoleColor? color, Ticker tick)
            : base(originalColumn, originalRow, color)
        {
            _ticker = tick;
            _ticker.OnSecondsTick += Second;
        }

        public void Dispose()
        {
            _ticker.OnSecondsTick -= Second;
        }


        #region ITimer Members

       private void Second()
        {
            DateTime dt = DateTime.Now;

            WriteAt(dt.Hour, 0, 0, 2);
            WriteAt(":", 2, 0);
            WriteAt(dt.Minute, 3, 0, 2);
            WriteAt(":", 5, 0);
            WriteAt(dt.Second, 6, 0, 2);
        }

        #endregion
    }

    public class HundredthSecondClock : Clock, IDisposable
    {
        private Ticker _ticker;
        public HundredthSecondClock(int originalColumn, int originalRow, ConsoleColor? color, Ticker tick)
            : base(originalColumn, originalRow, color)
        {
            _ticker = tick;
            _ticker.OnHundredthsTick += HundredthSecond;
        }
        private void HundredthSecond()
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

        public void Dispose()
        {
            _ticker.OnHundredthsTick -= HundredthSecond;
        }
    }

    public class TenthSecondClock : Clock, IDisposable
    {
        private Ticker _ticker;
        public TenthSecondClock(int originalColumn, int originalRow, ConsoleColor? color, Ticker tick)
            : base(originalColumn, originalRow, color)
        {
            _ticker = tick;
            _ticker.OnTenthsTick += TenthSecond;
        }

        public void Dispose()
        {
            _ticker.OnTenthsTick -= TenthSecond;
        }

        private void TenthSecond()
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


    }
}
