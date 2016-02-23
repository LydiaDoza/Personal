using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DecoratorDemo
{
    class Beverage : AbstractBeverageDecorator
    {
        public Beverage()
        {
            description = "DarkRoast";
        }
        public override double GetCost()
        {
            return 1.25;
        }

        public override string GetDescription()
        {
            return description;
        }

        public override void OtherMethods()
        {
            Console.WriteLine("Executing Other Methods");
        }
    }
}
