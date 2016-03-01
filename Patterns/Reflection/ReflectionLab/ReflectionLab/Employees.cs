using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Employee;

namespace ReflectionLab
{
    public class Employees
    {
        List<myEmployee> _employees = new List<myEmployee>();

        public void Add(string name, string address, int phone)
        {
            Console.WriteLine("   Employee with name {0} added to list.", name);
            _employees.Add(new myEmployee(name, address, phone));
        }

        public void DisplayAll()
        {
            Console.WriteLine("   DisplayAll() is called.");
            foreach (var employee in _employees)
            {
                Console.WriteLine(employee.Name);
                Console.WriteLine("   " + employee.Phone);
                Console.WriteLine("   " + employee.Address);
            }
        }
    }
}
