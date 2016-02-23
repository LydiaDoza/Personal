using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollection2016
{
    public abstract class AbstractIterator
    {
        protected Company inner;
        protected int current;

        public abstract void First();
        public abstract void MoveNext();
        public abstract bool IsDone();
        public abstract Employee GetCurrent();
    }
}
