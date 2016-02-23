using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class AmericanExpressCreditOrderDecorator : OrderDecorator
    {
        public AmericanExpressCreditOrderDecorator(AbstractOrderBase inner) : base(inner)
        { }

        public override double GetTotalCost()
        {
            return 5.0 + base.GetTotalCost();
        }

        public override void PrintOrderItems()
        {
            Console.WriteLine("Testing the American Express Decorator");
            Console.WriteLine();
            base.PrintOrderItems();

            Console.WriteLine("Grand Total with American Express Credit Card Charge {0:C}", GetTotalCost());
            Console.WriteLine();
            Console.WriteLine();
        }
    }
}
