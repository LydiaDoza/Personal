using System;
using System.Collections.Generic;
using System.Text;

namespace AcmeBooks
{
    partial class Order
    {
        //tracks the current state
        AbstractStates state;

        //the concrete states
        SelectingState selectingState;
        SupplyingDeliveryDetailsState supplyingDeliveryDetailsState;
        OrderPickingState orderPickingState;
        ReadyForShippingState readyForShippingState;
        ShippedState shippedState;

        private List<string> books = new List<string>();
        private int nPicked = 0;

        public Order()
        {
            selectingState = new SelectingState(this);
            supplyingDeliveryDetailsState = new SupplyingDeliveryDetailsState(this);
            orderPickingState = new OrderPickingState(this);
            readyForShippingState = new ReadyForShippingState(this);
            shippedState = new ShippedState(this);

            state = selectingState;
        }

        
        public void AddBook(string book)
        {
            state.AddBook(book);
        }

        public void SubmitOrder()
        {
            state.SubmitOrder();
        }

        public void DeliveryDetailsSupplied(string address)
        {
            state.DeliveryDetailsSupplied(address);
        }


        public void ItemPicked(string item)
        {
            state.ItemPicked(item);
        }


        public void Ship()
        {
            state.Ship();
        }

        private void InternalAddBook(string book)
        {
            books.Add(book);
            Console.WriteLine("{0} added to order", book);
        }

        private void InternalSubmitOrder()
        {
            Console.WriteLine("Order submitted");
        }

        private void InternalSupplyDeliveryDetails(string address)
        {
            Console.WriteLine("Delivery details: {0} ", address);
        }


        private void InternalItemPicked(string item)
        {
            nPicked++;

            Console.WriteLine("Picked item {0}", item);
            if (nPicked == books.Count)
            {
                Console.WriteLine("All items picked");
            }
        }


        public void InternalShip()
        {
            Console.WriteLine("Books have been shipped");
        }

    }
}
