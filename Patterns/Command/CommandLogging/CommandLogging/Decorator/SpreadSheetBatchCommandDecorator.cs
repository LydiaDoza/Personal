using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Command;
using SpreadSheet;

namespace Decorator
{
    public class SpreadSheetBatchCommandDecorator : SpreadSheetDecorator
    {
        private BatchInvoker _invoker;

        public SpreadSheetBatchCommandDecorator(ISpreadSheet spreadsheet) : base(spreadsheet)
        {
            _invoker = new BatchInvoker();
        }

        public override void SetValue(int nRow, int nCol, int val)
        {
            SetValueCommand command = new SetValueCommand(_inner, nRow, nCol, val);
            _invoker.Execute(command);
        }
    }
}
