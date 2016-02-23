using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorLibrary2016
{
    public abstract class AbstractIterator
    {
        protected CompanyComposite inner;
        protected int current;

        public abstract void First();
        public abstract void MoveNext();
        public abstract bool IsDone();
        public abstract CompanyComponent GetCurrent();
    }
}
