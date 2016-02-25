using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExternalCompositeIterator2016
{
    public class CompanyCompositeVisitor : IVisitor
    {
        public CompanyCompositeVisitor(CompanyComponent component)
        {
            component.Accept(this);
        }

        public void Visit(CompanyComposite composite)
        {
            Console.WriteLine(" Company Composite");
        }

        public void Visit(Employee employee)
        {
            Console.WriteLine("...");
        }
    }
}
