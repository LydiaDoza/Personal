using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DecoratorDemo
{
    class BeverageDecorator : AbstractBeverageDecorator
    {
        protected AbstractBeverageDecorator _inner;

        protected BeverageDecorator(AbstractBeverageDecorator inner)
        {
            _inner = inner;
        }
        public override double GetCost()
        {
            return _inner.GetCost();
        }

        public override string GetDescription()
        {
            return _inner.GetDescription();
        }

        public override void OtherMethods()
        {
            _inner.OtherMethods();
        }
    }
}
