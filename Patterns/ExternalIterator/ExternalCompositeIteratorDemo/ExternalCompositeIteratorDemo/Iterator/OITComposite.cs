using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    //Step 3--change the name of the OITClass class to be more representative of
    //a composite and have it inherit from OITComponent
    class OITComposite:OITComponent
    {
        //Step 4--change references from OITStudent to be of type OITComponent
        List<OITComponent> components = new List<OITComponent>();
        string _name;
        string _section;

        public OITComposite(string name, string section)
        {
            _name = name;
            _section = section;
        }

        //Step 5--override the Add and Remove methods of OITComponent
        //Override the CreateIterator method to return a ReturnAllterator for this type
        //Override the Display method--it is important that you understand this method
        public override void Add(OITComponent oitcomponent)
        {
            components.Add(oitcomponent);
        }

        public override void Remove(OITComponent oitcomponent)
        {
            components.Remove(oitcomponent);
        }

        internal override AbstractIterator CreateIterator()
        {
            return new ReturnAllIterator(this);
        }

        public override void Display()
        {
            Console.WriteLine(_name + " " + _section );

            AbstractIterator iter = CreateIterator();
            for (iter.First(); !iter.IsDone(); iter.MoveNext())
            {
                iter.GetCurrent().Display();
            }
        }

        //Step 6--refactor--changed from GetStudents method of the OITClass
        // to GetOITComponets from the OITComponent class
        public override List<OITComponent> GetOITComponents()
        {
            return components;
        }

        public string Name
        {
            get { return _name; }
        }

        public string Section
        {
            get { return _section; }
        }

        public override  void NodeDisplay()
        {
            Console.WriteLine("************    " + _name + "  ************"); 
        }
    }
}
