using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorLibrary2016
{
    public class CompanyComposite : CompanyComponent
    {
        private string _name;
        private string _description;
        List<CompanyComponent> _components = new List<CompanyComponent>();
        public string Name => _name;
        public string Description => _description;

        public CompanyComposite(string name, string description)
        {
            _name = name;
            _description = description;
        }

        public override void Add(CompanyComponent e)
        {
            _components.Add(e);
        }

        public override void Remove(CompanyComponent e)
        {
            _components.Remove(e);
        }

        public override List<CompanyComponent> GetCompanyComponents() 
            => _components;

        public override string GetName() => _name;

        public override AbstractIterator CreateIterator() 
            => new InternalReturnAllIterator(this);

        public override void Display()
        {
            Console.WriteLine(_name);
            AbstractIterator iter = CreateIterator();

            for(iter.First(); !iter.IsDone(); iter.MoveNext())
                iter.GetCurrent().Display();
        }
    }
}
