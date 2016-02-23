using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class ReturnGoodGradesIterator : AbstractIterator
    {
        private int grade;

        public ReturnGoodGradesIterator(OITClass patterns, int score)
        {
            inner = patterns;
            current = 0;
            grade = score;
        }

        public override void First()
        {
            current = 0;
            while (!IsDone() && inner.GetStudents()[current].TestGrade < grade)
                ++current;
        }

        public override void MoveNext()
        {
            ++current;
            while (!IsDone() && inner.GetStudents()[current].TestGrade < grade)
                ++current;
        }

        public override bool IsDone()
        {
            return current > inner.GetStudents().Count - 1;
        }

        public override OITStudent GetCurrent()
        {
            if (IsDone())
                Console.WriteLine("Throw and exception?");

            return inner.GetStudents()[current];
        }
    }
}
