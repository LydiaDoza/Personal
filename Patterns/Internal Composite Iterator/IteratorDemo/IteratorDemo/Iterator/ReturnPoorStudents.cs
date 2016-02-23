using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class ReturnPoorStudents : AbstractIterator
    {
        private int _grade;
        
        public ReturnPoorStudents(OITClass patterns, int grade)
        {
            inner = patterns; _grade = grade; current = 0;
        }
        public override void First()
        {
            current = 0;
            while (!IsDone() && inner.GetStudents()[current].TestGrade > _grade)
                ++current;
        }      

        public override void MoveNext()
        {
            ++current;
            while (!IsDone() && inner.GetStudents()[current].TestGrade > _grade)
                ++current;
        }

        public override bool IsDone()
        {
            return current > inner.GetStudents().Count - 1;
        }

        public override OITStudent GetCurrent()
        {
            if (IsDone())
                Console.WriteLine();
            return inner.GetStudents()[current];
        }

        
    }
}
