using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Command;
using SpreadSheet;

namespace Decorator
{
    public class SpreadSheetCommandLogDecorator : SpreadSheetDecorator
    {
        CommandHistoryInvoker invoker;

        public SpreadSheetCommandLogDecorator(ISpreadSheet spreadsheet)
            : base(spreadsheet)
        {
            invoker = new CommandHistoryInvoker(
                String.Format("{0}.log", spreadsheet.Name));
        }

        public override void SetValue(int nRow, int nCol, int value)
        {
            ICommand command = new SetValueCommand(
                _inner, nRow, nCol, value);
            invoker.Execute(command);
        }

        public override void Save(string filename)
        {
            _inner.Save(filename);
            invoker.ClearHistory();
        }

        public void Restore()
        {
            invoker.Restore();
        }
    }
}
