using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpreadSheet
{
    public class SpreadSheetRegistrySingleton
    {
        private Dictionary<string, ISpreadSheet> sheets = new Dictionary<string, ISpreadSheet>();

        private static object _initLock = new object();

        private static SpreadSheetRegistrySingleton _instance;

        public static SpreadSheetRegistrySingleton GetInstance()
        {
            if (_instance == null)
            {
                lock (_initLock)
                {
                   if (_instance == null)
                   {
                       _instance = new SpreadSheetRegistrySingleton();
                   }
                }
            }
            return _instance;
        }

        public ISpreadSheet GetSheetByName(string name)
        {
            return sheets[name];
        }

        public void RegisterSheet(string name, ISpreadSheet sheet)
        {
            sheets[name] = sheet;
        }

        public void UnRegisterSheet(string name)
        {
            sheets[name] = null;
        }        
    }
}
