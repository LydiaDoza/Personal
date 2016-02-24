using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace EmployeeCollection2016
{
    public class InternalFatCatsIterator : AbstractIterator
    {
        public InternalFatCatsIterator(Company co)
        {
            inner = co;
            current = 0;
        }
        public override void First()
        {
            current = 0;

            while (!IsDone() && inner.GetEmployees()[current].Salary < 10)
                ++current;
        }

        public override void MoveNext()
        {
            ++current;

            while (!IsDone() && inner.GetEmployees()[current].Salary < 10)
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
