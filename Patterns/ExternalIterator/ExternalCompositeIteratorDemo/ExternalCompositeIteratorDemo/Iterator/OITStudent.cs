using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    //Step 2--derive OITStudent from OITComponent override the Display() method
    class OITStudent:OITComponent
    {
        string _name;
        int _id;
        int _testgrade;

        public OITStudent(string name, int id, int testgrade)
        {
            _name = name;
            _id = id;
            _testgrade = testgrade;
        }

        public override int TestGrade
        {
            get { return _testgrade; }
        }

        public override void Display()
        {
            Console.WriteLine(" {0}, {1}, {2} ",
                _name, _id, _testgrade);
        }

        public override void NodeDisplay()
        {
            Console.WriteLine(" {0}, {1}, {2} ",
                _name, _id, _testgrade);
        }
    }
}
