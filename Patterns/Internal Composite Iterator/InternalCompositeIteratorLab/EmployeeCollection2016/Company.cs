using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollection2016
{
    public class Company
    {
        private string _name { get; }
        private string _description { get; }
        List<Employee> _employees = new List<Employee>();

        public Company(string name, string description)
        {
            _name = name;
            _description = description;
        }

        public void AddEmployee(Employee e)
        {
            _employees.Add(e);
        }

        public List<Employee> GetEmployees()
        {
            return _employees;
        }

        public IEnumerable<Employee> GetIter()
        {
            return _employees;
        } 
    }
}
