using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorLibrary2016
{
    public class CompanyComponent
    {
        /************************************************************
        *   Since the CompanyComponent methods might not be 
        *   implemented by all child classes, throwing exceptions are
        *   the default behavior.
        ************************************************************/
        public virtual void Add(CompanyComponent companyComponent)
        {
            throw new Exception("Unsupported Operation");
        }

        public virtual void Remove(CompanyComponent companyComponent)
        {
            throw new Exception("Unsupported Operation");
        }

        public virtual List<CompanyComponent> GetCompanyComponents()
        {
            throw new Exception("Unsupported Operation");
        }

        public virtual string GetName()
        {
            throw new Exception("Unsupported Operation");
        }

        public virtual AbstractIterator CreateIterator()
        {
            throw new Exception("Unsupported Operation");   
        }

        public virtual void Display()
        {
            throw new Exception("Unsupported Operation");
        }
    }
}
