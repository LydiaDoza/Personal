using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
//using EmployeeCollection2016;
using InternalCompositeIteratorLibrary2016;

namespace InternalCompositeIteratorLab
{
    class Program
    {
        //    static void PrintEmployees(AbstractIterator iter)
        //    {
        //        for (iter.First(); !iter.IsDone(); iter.MoveNext())
        //        {
        //            try
        //            {
        //                iter.GetCurrent().DisplayEmployee();
        //            }
        //            catch (Exception e)
        //            {
        //                Console.WriteLine(e.Message);
        //            }
        //        }
        //    }

        static void Main(string[] args)
        {
            //Company myCo = new Company("A co", "Some Company");
            //myCo.AddEmployee(new Employee("Worst Employee", "123-45-6789", 0.6));
            //myCo.AddEmployee(new Employee("bob", "SSN", 123));
            //myCo.AddEmployee(new Employee("Best Employee", "321-45-2341", 100000.65));
            //myCo.AddEmployee(new Employee("Sally", "SSSSN", 500));
            //myCo.AddEmployee(new Employee("Bad Employee", "sssn", 5));


            CompanyComposite myCo = new CompanyComposite("A co.", "Some Company");
            myCo.Add(new Employee("Best Employee", "123-45-6789", 5432.9));
            myCo.Add(new Employee("2nd Best Employee", "234-56-8901", 3.33));
            myCo.Add(new Employee("An Employee", "43729", 1852.9));
            myCo.Add(new Employee("Wost Employee", "2", 0.3));

            CompanyComposite moo = new CompanyComposite("Moo", "Makes Cow Noises");
            moo.Add(new Employee("Janet", "snnnnn", 109832.50));

            CompanyComposite blue = new CompanyComposite("Blue", "Makes all things blue");
            blue.Add(new Employee("Frank", "132-23-1323", 12.21));
            blue.Add(myCo);
            blue.Add(moo);

            CompanyComposite coo = new CompanyComposite("Coo", "Makes Pigeon Noises");
            coo.Add(new Employee("Charles", "sssssn", 4500.00));
            coo.Add(blue);

            CompanyComposite newforyou = new CompanyComposite("NewForYou", "Owns companies whose name's rhyme.");
            newforyou.Add(new Employee("Rey", "444-44-4444", 321312.32));
            newforyou.Add(coo);

            newforyou.Display();

            //InternalFatCatsIterator fatIter = new InternalFatCatsIterator(myCo);
            //    PrintEmployees(fatIter);

            Console.Read();
        }
    }
}