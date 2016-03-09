using System;
using System.Collections.Generic;
using System.Text;

namespace AcmeBooks
{
    class Program
    {
        private static void OrderWithState()
        {
            Order order = new Order();

            order.AddBook("foo");
            order.AddBook("bar");

            order.SubmitOrder();
            // uncomment to show problem
            //order.Ship();

            order.DeliveryDetailsSupplied("123 Johnson Street, KFalls Or, 97601");

            order.ItemPicked("foo");
            order.ItemPicked("bar");

            order.Ship();
        }
        
        static void Main(string[] args)
        {
            OrderWithState();
        }        
    }
}
