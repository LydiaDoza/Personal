using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DecoratorDemo
{
    class Sprinkles : BeverageDecorator
    {
        public Sprinkles(AbstractBeverageDecorator inner) : base(inner)
        { }

        public override double GetCost()
        {
            return 1.5 + _inner.GetCost();
        }

        public override string GetDescription()
        {
            return string.Format("Sprinkles + " + _inner.GetDescription());
        }
    }
}
