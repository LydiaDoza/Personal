using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class OrderItem
    {
        private string productCode;
        private int quantity;
        private double unitCost;
        private double unitWeight;

        public OrderItem(string productCode, int quantity, double unitCost, double unitWeight)
        {
            this.productCode = productCode;
            this.quantity = quantity;
            this.unitCost = unitCost;
            this.unitWeight = unitWeight;
        }

        public string ProductCode
        {
            get { return productCode; }
        }

        public int Quantity
        {
            get { return quantity; }
        }

        public double UnitCost
        {
            get { return unitCost; }
        }

        public double Cost
        {
            get { return unitCost * quantity; }
        }

        public double UnitWeight
        {
            get { return unitWeight; }
        }

        public double GetWeight
        {
            get { return unitWeight * quantity; }
        }
    }
}
