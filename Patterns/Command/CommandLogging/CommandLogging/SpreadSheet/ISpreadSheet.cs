using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpreadSheet
{
    
    public interface ISpreadSheet
    {
        int GetValue(int nRow, int nCol);
        void SetValue(int nRow, int nCol, int value);
        string Name { get; }
        int NumberOfColumns { get; }
        int NumberOfRows { get; }
        void Save(string filename);        
    }
}
