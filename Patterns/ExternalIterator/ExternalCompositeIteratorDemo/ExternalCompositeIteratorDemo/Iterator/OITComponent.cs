using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    //Step 1--create a component base class and add the essential methods
    //for both the leaf classes and the composite classes
    class OITComponent
    {
        
        public virtual void Add(OITComponent oitcomponent)
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual void Remove(OITComponent oitcomponent)
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual List<OITComponent> GetOITComponents()
        {
            throw new System.Exception("Unsupported Operation");
        }

        internal virtual AbstractIterator CreateIterator()
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual void Display()
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual void NodeDisplay()
        {
            throw new System.Exception(); 
        }

        public virtual int TestGrade
        {
            get
            {
                return 0;
            }
        }
    }
}
