using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calc
{
    struct StructOne
    {
        int x;
        double y;
    }

    public class CBase
    {
        public int total;
    }
    
    public class Calculator : CBase
    {
        public int Add(int x, int y)
        {
            return x + y;
        }

        public int Sub(int x, int y)
        {
            return x - y;
        }
    }
}
