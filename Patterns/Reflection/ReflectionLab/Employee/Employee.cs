using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee
{
    public class myEmployee
    {
        private readonly string _name;
        public string Name => _name;

        private readonly string _address;
        public string Address => _address;

        private readonly int _phone;
        public int Phone => _phone;

        public myEmployee(string name, string address, int phone)
        {
            _name = name;
            _address = address;
            _phone = phone;
        }
    }
}
