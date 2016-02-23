using System;
using System.Collections.Generic;
using System.Text;

namespace GammaConsoleClockObserver
{
    public interface ITimerObserver
    {
        void HundredthSecond();
        void TenthSecond();
        void Second();
        void Minute();
        void Hour();
    }
}
