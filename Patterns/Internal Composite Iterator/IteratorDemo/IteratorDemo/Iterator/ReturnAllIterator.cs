using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class ReturnAllIterator : AbstractIterator
    {
        public ReturnAllIterator(OITClass patterns)
        {
            inner = patterns;
            current = 0;
        }

        public override void First()
        {
            current = 0;
        }

        public override void MoveNext()
        {
            ++current;
        }

        public override bool IsDone()
        {
            return current > inner.GetStudents().Count - 1;
        }

        public override OITStudent GetCurrent()
        {
            if (IsDone())
                Console.WriteLine("Maybe throw and exception?");

            return inner.GetStudents()[current];

        }
    }
}
