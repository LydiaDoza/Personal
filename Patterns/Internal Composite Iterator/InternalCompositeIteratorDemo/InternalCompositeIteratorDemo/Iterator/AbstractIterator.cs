using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    //Step 7--refactor the iterator base class to use OITComponent
    abstract class AbstractIterator
    {
        protected int current;
        protected OITComponent inner;

        public abstract void First();
        public abstract void MoveNext();
        public abstract bool IsDone();
        public abstract OITComponent GetCurrent();
    }
}
