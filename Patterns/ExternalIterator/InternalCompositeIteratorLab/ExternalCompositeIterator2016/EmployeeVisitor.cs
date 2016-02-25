using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExternalCompositeIterator2016
{
    public class EmployeeVisitor:IVisitor
    {
        public EmployeeVisitor(CompanyComponent component)
        {
            component.Accept(this);
        }

        public void Visit(CompanyComposite composite)
        {
            Console.WriteLine("...");
        }

        public void Visit(Employee employee)
        {
            Console.WriteLine(" Employee");
        }
    }
}
