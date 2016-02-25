using System;

namespace ExternalCompositeIterator2016
{
    public class Employee : CompanyComponent
    {
        private string _name;
        private string _socialSecurityNumber;
        private double _salary;

        public override string GetName()
        {
            return _name;
        }
        public string Name
        {
            get { return _name; }
        }
        public string SocialSecurityNumber
        {
            get { return _socialSecurityNumber; }
        }
        public double Salary
        {
            get { return _salary; }
        }


        public Employee(string name, string ssn, double salary)
        {
            _name = name;
            _socialSecurityNumber = ssn;
            _salary = salary;
        }


        public override void Display()
        {
            Console.WriteLine();
            Console.WriteLine("Name: {0}", _name);
            Console.WriteLine("   SSN: {0}", _socialSecurityNumber);
            Console.WriteLine("   Salary: {0:C}", _salary);
            Console.WriteLine();
        }
        public override void NodeDisplay()
        {
            Console.WriteLine(_name);
        }

        public override void Accept(IVisitor visitor)
        {
            visitor.Visit(this);
        }
    }
}
