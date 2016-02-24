using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollection2016
{
    public class InternalReturnAllIterator : AbstractIterator
    {
        public InternalReturnAllIterator(Company co)
        {
            inner = co;
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

        public override bool IsDone() => current > inner.GetEmployees().Count - 1;

        public override Employee GetCurrent()
        {
            if (IsDone())
                throw new Exception("Out of Employees");

            return inner.GetEmployees()[current];
        }
    }
}
