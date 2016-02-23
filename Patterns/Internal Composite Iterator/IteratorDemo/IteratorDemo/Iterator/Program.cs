using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class Program
    {
        private static void PrintStudents(AbstractIterator iter)
        {
            for (iter.First(); !iter.IsDone(); iter.MoveNext())
            {
                iter.GetCurrent().DisplayStudent();
            }
        }
        static void Main(string[] args)
        {
            OITClass patterns = new OITClass("Patterns");

            patterns.AddStudent(new OITStudent("Jim", 1, 80));
            patterns.AddStudent(new OITStudent("Bob", 2, 85));
            patterns.AddStudent(new OITStudent("Rick", 3, 60));
            patterns.AddStudent(new OITStudent("Sue", 4, 95));
            patterns.AddStudent(new OITStudent("Alex", 5, 66));
            patterns.AddStudent(new OITStudent("Sally", 6, 77));
            patterns.AddStudent(new OITStudent("Susan", 7, 80));
            patterns.AddStudent(new OITStudent("Ralph", 8, 98));

            List<OITStudent> allstudents = patterns.GetStudents();

            //allstudents.Add(new OITStudent("Todd", 9, 94));
            //IEnumerable<OITStudent> iterstudents = patterns.GetIter();
            //iterstudents.Add???

            //for (int i = 0; i < allstudents.Count; i++)
            //{
            //    allstudents[i].DisplayStudent();
            //}

            //foreach (OITStudent student in allstudents)
            //{
            //    student.DisplayStudent();
            //    //allstudents.Add??
            //}

            //foreach (OITStudent student in iterstudents)
            //{
            //    student.DisplayStudent();
            //}

            //List<OITStudent> smartstudents = patterns.GetStudents();
            //for (int i = 0; i < smartstudents.Count; i++)
            //{
            //    if (smartstudents[i].TestGrade > 85)
            //    {
            //        smartstudents[i].DisplayStudent();
            //    }
            //}    

            //AbstractIterator PoorStudents = new ReturnPoorStudents(patterns, 85);
            //PrintStudents(PoorStudents);

            //AbstractIterator AllStudents = new ReturnAllIterator(patterns);
            AbstractIterator SmartStudents = new ReturnGoodGradesIterator(patterns, 85);
            PrintStudents(SmartStudents);

        }
    }
}
