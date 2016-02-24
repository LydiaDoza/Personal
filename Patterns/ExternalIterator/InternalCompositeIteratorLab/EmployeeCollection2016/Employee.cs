using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollection2016
{
    public class Employee
    {
        private string _name;
        private string _socialSecurityNumber;
        private double _salary;

        public string Name => _name;
        public string SocialSecurityNumber => _socialSecurityNumber;
        public double Salary => _salary;


        public Employee(string name, string ssn, double salary)
        {
            _name = name;
            _socialSecurityNumber = ssn;
            _salary = salary;
        }

        public void DisplayEmployee()
        {
            Console.WriteLine("Name: {0}", _name);
            Console.WriteLine("   SSN: {0}", _socialSecurityNumber);
            Console.WriteLine("   Salary: {0:C}", _salary);
            Console.WriteLine();
        }
    }
}
