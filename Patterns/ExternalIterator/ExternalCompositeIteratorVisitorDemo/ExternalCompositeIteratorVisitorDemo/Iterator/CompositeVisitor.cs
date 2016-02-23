using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class CompositeVisitor : IVisitor
    {
        public CompositeVisitor(OITComponent component)
        {
            component.Accept(this);
        }

        public void Visit(OITStudent student)
        {
            Console.WriteLine("Do nothing");
        }

        public void Visit(OITComposite composite)
        {
            Console.WriteLine("I am at at composite node");
        }
    }
}
