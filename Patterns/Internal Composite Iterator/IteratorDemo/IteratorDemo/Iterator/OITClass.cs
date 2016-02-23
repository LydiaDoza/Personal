using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class OITClass
    {

        List<OITStudent> students = new List<OITStudent>();

        string _name;
        public string Name
        {
            get { return _name; }
        }

        public OITClass(string name)
        {
            _name = name;
        }

        public void AddStudent(OITStudent student)
        {
            students.Add(student);
        }

        public List<OITStudent> GetStudents()
        {
            return students;
        }

        public IEnumerable<OITStudent> GetIter()
        {
            return students;
        }
        
    }
}
