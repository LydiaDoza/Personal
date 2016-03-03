using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SpreadSheet;


namespace Command
{
    [Serializable]
    public class SetValueCommand:ICommand
    {
        private string sheetname;
        private int nRow;
        private int nCol;
        int value;

        public SetValueCommand(ISpreadSheet sheet, int nRow, int nCol, int value)
        {
            this.sheetname = sheet.Name;//performance issue here
            this.nRow = nRow;
            this.nCol = nCol;
            this.value = value;
        }
        
        public void Execute()
        {
            ISpreadSheet spreadsheet = 
                SpreadSheetRegistrySingleton.GetInstance().GetSheetByName(sheetname);
            spreadsheet.SetValue(nRow, nCol, value);
        }
    }
}
