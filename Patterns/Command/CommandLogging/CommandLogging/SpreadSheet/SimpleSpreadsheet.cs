using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;


namespace SpreadSheet
{
    [Serializable]
    public class SimpleSpreadsheet:ISpreadSheet
    {
        private string name;
        int nCols = 10;
        int nRows = 10;
        private int[,] cells = new int[10, 10];

        public SimpleSpreadsheet(string name)
        {
            this.name = name;
            SpreadSheetRegistrySingleton.GetInstance().RegisterSheet(name, this);
        }

        public int GetValue(int nRow, int nCol)
        {
            return cells[nRow, nCol];
        }

        public void SetValue(int nRow, int nCol, int value)
        {
            cells[nRow, nCol] = value;
        }

        public string Name
        {
            get { return name; }
            
        }

        public int NumberOfColumns
        {
            get { return nCols; }
        }

        public int NumberOfRows
        {
            get { return nRows; }
        }

        public void Save(string filename)
        {
            using (FileStream stream = File.OpenWrite(filename))
            {
                BinaryFormatter formatter = new BinaryFormatter();

                formatter.Serialize(stream, this);
            }
        }

        public static ISpreadSheet Load(string filename)
        {
            SimpleSpreadsheet sheet;

            using (FileStream stream = File.OpenRead(filename))
            {
                BinaryFormatter formatter = new BinaryFormatter();

                sheet = (SimpleSpreadsheet)formatter.Deserialize(stream);

                SpreadSheetRegistrySingleton.GetInstance().RegisterSheet(sheet.Name, sheet);
            }

            return sheet;
        }
    }
}
