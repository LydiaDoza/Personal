using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class ExpressDeliveryOrderDecorator : OrderDecorator
    {
        public ExpressDeliveryOrderDecorator(AbstractOrderBase inner) : base(inner)
        { }

        public override double GetTotalCost()
        {
            // add $4 shipping to the total cost from the 
            // original order calculation
            return 4.0 + _inner.GetTotalCost();
        }

        public override void PrintOrderItems()
        {
            Console.WriteLine("Testing the Express Delivery Decorator");
            Console.WriteLine();

            base.PrintOrderItems();
            Console.WriteLine("Grand Total with Shipping {0:C}", GetTotalCost());
            Console.WriteLine();
            Console.WriteLine();

        }
    }
}
