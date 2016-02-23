using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class Program
    {
        static void Main(string[] args)
        {
            //Step 9 create a composite data structure and polymorphically call
            //OITComponent.Display
            OITComponent patterns1 = new OITComposite("Patterns1", "Section 1");

            patterns1.Add(new OITStudent("Jim", 1, 90));
            patterns1.Add(new OITStudent("Bob", 1, 85));
            patterns1.Add(new OITStudent("Rick", 1, 60));
            patterns1.Add(new OITStudent("Sue", 1, 95));
            patterns1.Add(new OITStudent("Alex", 1, 66));
            patterns1.Add(new OITStudent("Sally", 1, 77));
            patterns1.Add(new OITStudent("Susan", 1, 80));
            patterns1.Add(new OITStudent("Ralph", 1, 98));

            //patterns1.GetOITComponents()[0].Display();

            OITComponent patterns2 = new OITComposite("Patterns2", "Section 2");

            patterns2.Add(new OITStudent("Sally", 1, 90));
            patterns2.Add(new OITStudent("Keith", 1, 85));
            patterns2.Add(new OITStudent("Cameron", 1, 60));
            patterns2.Add(new OITStudent("Kelsea", 1, 95));
            patterns2.Add(new OITStudent("Alexia", 1, 66));

            OITComponent patternsclasses = new OITComposite("Patterns classes", "Sections included");

            patternsclasses.Add(patterns1);
            patternsclasses.Add(patterns2);

            OITComponent seniorproject = new OITComposite("Senior Project", "Section 1");
            seniorproject.Add(new OITStudent("Alise", 1, 90));
            seniorproject.Add(new OITStudent("Vera", 1, 85));
            seniorproject.Add(new OITStudent("Carol", 1, 60));
            seniorproject.Add(new OITStudent("Dave", 1, 95));
            seniorproject.Add(new OITStudent("Jesse", 1, 66));

            OITComponent allclasses = new OITComposite("All classes", "Sections Included");
            allclasses.Add(patternsclasses);
            allclasses.Add(seniorproject);

            // allclasses.Display();
            //AbstractIterator iter = allclasses.CreateIterator();
            //for (iter.First(); !iter.IsDone(); iter.MoveNext())
            //{
            //    iter.GetCurrent().Display();
            //}     

            //AbstractIterator iter = new CompositeIterator(allclasses);

            //for (iter.First(); !iter.IsDone(); iter.MoveNext())
            //{
            //    iter.GetCurrent().NodeDisplay();
            //}

            int studentCount = 0;
            int totalGrades = 0;
            AbstractIterator iter = new CompositeIterator(allclasses);
            for (iter.First(); !iter.IsDone(); iter.MoveNext())
            {
                totalGrades += iter.GetCurrent().TestGrade;
                if (iter.GetCurrent() is OITStudent)
                    ++studentCount;
            }

            Console.WriteLine("The average student grade is {0}",
                totalGrades/studentCount);

        }
    }
}
