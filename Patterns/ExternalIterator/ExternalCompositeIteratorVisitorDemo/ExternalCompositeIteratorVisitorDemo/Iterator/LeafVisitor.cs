using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class LeafVisitor : IVisitor
    {
        public LeafVisitor(OITComponent component)
        {
            component.Accept(this);
        }

        public void Visit(OITStudent student)
        {
            Console.WriteLine("I am a student node");
        }

        public void Visit(OITComposite composite)
        {
            Console.WriteLine("Do nothing");
        }
    }
}
