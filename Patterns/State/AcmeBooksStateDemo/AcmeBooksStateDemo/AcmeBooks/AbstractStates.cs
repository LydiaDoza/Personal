using System;
using System.Collections.Generic;
using System.Text;

namespace AcmeBooks
{
    abstract class AbstractStates
    {
        // forward reference
        protected Order order;
        public AbstractStates(Order order)
        {
            this.order = order;
        }

        public virtual void AddBook(string book)
        {
            throw new InvalidOperationException("AddItem");
        }

        public virtual void SubmitOrder()
        {
            throw new InvalidOperationException("SubmitOrder");
        }

        public virtual void DeliveryDetailsSupplied(string address)
        {
            throw new InvalidOperationException("SetDeliveryDetails");
        }


        public virtual void ItemPicked(string item)
        {
            throw new InvalidOperationException("PickedItem");
        }


        public virtual void Ship()
        {
            throw new InvalidOperationException("Ship");
        }

    }
}
