using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class OrderDecorator : AbstractOrderBase
    {
        protected AbstractOrderBase _inner;

        protected OrderDecorator(AbstractOrderBase inner)
        {
            _inner = inner;
        }

        public override void AddItem(string productCode, int quantity, double cost, double weight)
        {
            _inner.AddItem(productCode, quantity, cost, weight);
        }

        public override double GetTotalCost()
        {
            return _inner.GetTotalCost();
        }

        public override void PrintOrderItems()
        {
            _inner.PrintOrderItems();
        }
    }
}
