using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    abstract class AbstractIterator
    {
        protected OITClass inner;
        protected int current;

        public abstract void First();
        public abstract void MoveNext();
        public abstract bool IsDone();
        public abstract OITStudent GetCurrent();
    }
}
