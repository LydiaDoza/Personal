using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class OITStudent
    {
        string _name;
        int _id;

        int _testgrade;
        public int TestGrade
        {
            get { return _testgrade; }
        }

        public OITStudent(string name, int id, int testgrade)
        {
            _name = name;
            _id = id;
            _testgrade = testgrade;
        }

        

        public void DisplayStudent()
        {
            Console.WriteLine(" {0}, {1}, {2} ",
                _name, _id, _testgrade);
        }
    }
}
