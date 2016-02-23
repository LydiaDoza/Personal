using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DecoratorDemo
{
    class Program
    {
        private static void ProduceReceipt(AbstractBeverageDecorator beverage)
        {
            Console.WriteLine("You have ordered a {0}", beverage.GetDescription());
            Console.WriteLine("The cost is {0:C}", beverage.GetCost());

            beverage.OtherMethods();
        }
        static void Main(string[] args)
        {
            AbstractBeverageDecorator DarkRoast = new Beverage();
            AbstractBeverageDecorator Sprinkles = new Sprinkles(DarkRoast);
            ProduceReceipt(Sprinkles);
        }
    }
}
