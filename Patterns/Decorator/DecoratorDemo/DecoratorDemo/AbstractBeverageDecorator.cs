using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DecoratorDemo
{
    public abstract class AbstractBeverageDecorator
    {
        protected string description;
        public abstract string GetDescription();
        public abstract double GetCost();
        public abstract void OtherMethods();
    }
}
