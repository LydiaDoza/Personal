using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SpreadSheet;

namespace Decorator
{
    public class SpreadSheetDecorator:ISpreadSheet
    {
        protected ISpreadSheet _inner;

        public SpreadSheetDecorator(ISpreadSheet spreadsheet)
        {
            _inner = spreadsheet;
        }
        
        public virtual int GetValue(int nRow, int nCol)
        {
            return _inner.GetValue(nRow, nCol);
        }

        public virtual void SetValue(int nRow, int nCol, int value)
        {
            _inner.SetValue(nRow, nCol, value);
        }

        public virtual string Name
        {
            get { return _inner.Name; }
        }

        public virtual int NumberOfColumns
        {
            get { return _inner.NumberOfColumns; }
        }

        public virtual int NumberOfRows
        {
            get { return _inner.NumberOfRows; }
        }

        public virtual void Save(string filename)
        {
            _inner.Save(filename);
        }        
    }
}
