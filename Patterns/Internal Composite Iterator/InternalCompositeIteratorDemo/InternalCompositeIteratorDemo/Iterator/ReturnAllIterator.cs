using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    //Step 8--refactor ReturnAllIterator to use the OITComponent type
    class ReturnAllIterator : AbstractIterator
    {
        public ReturnAllIterator(OITComponent patterns)
        {
            current = 0;
            inner = patterns;
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
            return current > inner.GetOITComponents().Count - 1;
        }
        public override OITComponent GetCurrent()
        {
            if (IsDone())
                Console.WriteLine("Maybe throw exception?");

            return inner.GetOITComponents()[current];
        }
    }
}
