using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
   public class VisaCreditOrderDecorator : OrderDecorator
    {
        public VisaCreditOrderDecorator(AbstractOrderBase inner) : base(inner)
        { }
        public override double GetTotalCost()
        {
            return 2.0 + base.GetTotalCost();
        }

        public override void PrintOrderItems()
        {
            Console.WriteLine("Testing the Visa Credit Decorator");
            Console.WriteLine();

            base.PrintOrderItems();

            Console.WriteLine("Grand Total with Visa Credit Card Charge {0:C}", GetTotalCost());
            Console.WriteLine();
            Console.WriteLine();

        }
    }
}
