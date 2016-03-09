using System;
using System.Collections.Generic;
using System.Text;

namespace AcmeBooks
{
    partial class Order
    {
        //These classes are defined inside the Order class!
        public class SelectingState : AbstractStates
        {
            public SelectingState(Order order)
                : base(order)
            {

            }

            public override void AddBook(string book)
            {
                order.InternalAddBook(book);
            }

            public override void SubmitOrder()
            {
                order.InternalSubmitOrder();
                order.state = order.supplyingDeliveryDetailsState;
            }
        }

        public class SupplyingDeliveryDetailsState : AbstractStates
        {
            public SupplyingDeliveryDetailsState(Order order)
                : base(order)
            {

            }

            public override void DeliveryDetailsSupplied(string address)
            {
                order.InternalSupplyDeliveryDetails(address);
                order.state = order.orderPickingState;
            }
        }

        public class OrderPickingState : AbstractStates
        {
            public OrderPickingState(Order order)
                : base(order)
            {

            }

            public override void ItemPicked(string item)
            {
                order.InternalItemPicked(item);

                if (order.nPicked == order.books.Count)
                {
                    order.state = order.readyForShippingState;
                }
            }
        }

        public class ReadyForShippingState : AbstractStates
        {
            public ReadyForShippingState(Order order)
                : base(order)
            {

            }

            public override void Ship()
            {
                order.InternalShip();
                order.state = order.shippedState;
            }
        }

        public class ShippedState : AbstractStates
        {
            public ShippedState(Order order)
                : base(order)
            {

            }
        }
    }
}
