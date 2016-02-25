using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using ExternalCompositeIterator2016;

namespace InternalCompositeIteratorLab
{
    class Program
    {

        static void Main(string[] args)
        {
            CompanyComponent myCo = new CompanyComposite("A co.", "Some Company");
            myCo.Add(new Employee("Best Employee", "123-45-6789", 5432.9));
            myCo.Add(new Employee("2nd Best Employee", "234-56-8901", 3.33));
            myCo.Add(new Employee("An Employee", "43729", 1852.9));
            myCo.Add(new Employee("Wost Employee", "2", 0.3));

            CompanyComponent moo = new CompanyComposite("Moo", "Makes Cow Noises");
            moo.Add(new Employee("Janet", "snnnnn", 109832.50));

            CompanyComposite blue = new CompanyComposite("Blue", "Makes all things blue");
            blue.Add(new Employee("Frank", "132-23-1323", 12.21));
            blue.Add(myCo);
            blue.Add(moo);

            CompanyComponent coo = new CompanyComposite("Coo", "Makes Pigeon Noises");
            coo.Add(new Employee("Charles", "sssssn", 4500.00));
            coo.Add(blue);

            CompanyComponent newforyou = new CompanyComposite("NewForYou", "Owns companies whose name's rhyme.");
            newforyou.Add(new Employee("Rey", "444-44-4444", 321312.32));
            newforyou.Add(coo);

            CompositeIterator iter = new CompositeIterator(newforyou);


            Console.WriteLine("=============== Part One ===============");
            for (iter.First(); !iter.IsDone(); iter.MoveNext()) 
            {
                if (iter.GetCurrent() is CompanyComposite||
                iter.GetCurrent() is Employee)
                {
                    iter.GetCurrent().NodeDisplay();
               }
            }
            Console.WriteLine();
            Console.WriteLine("=============== Part Two ===============");

            Console.WriteLine("----------- Employee Visitor -----------");
            IVisitor empVisitor = new EmployeeVisitor(newforyou);

            Console.WriteLine("---------- Composite Visitor -----------");
            IVisitor coVisitor = new CompanyCompositeVisitor(newforyou);
            Console.Read();
        }
    }
}
