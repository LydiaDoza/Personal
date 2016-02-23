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
            OITComponent patterns1 = new OITComposite("Patterns", "Section 1");

            patterns1.Add(new OITStudent("Jim", 1, 90));
            patterns1.Add(new OITStudent("Bob", 1, 85));
            patterns1.Add(new OITStudent("Rick", 1, 60));
            patterns1.Add(new OITStudent("Sue", 1, 95));
            patterns1.Add(new OITStudent("Alex", 1, 66));
            patterns1.Add(new OITStudent("Sally", 1, 77));
            patterns1.Add(new OITStudent("Susan", 1, 80));
            patterns1.Add(new OITStudent("Ralph", 1, 98));

            OITComponent patterns2 = new OITComposite("Patterns", "Section 2");

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

            allclasses.Display();
        }
    }
}
