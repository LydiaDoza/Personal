using System;
using System.Collections.Generic;
using System.Text;

namespace GammaConsoleClockObserver
{
    public class Clock
    {
        protected int originalRow;
        protected int originalColumn;
        
        //nullable type--allows color to be an actual value or "null"
        ConsoleColor? color;

        public Clock(int originalColumn, int originalRow, ConsoleColor? color)
        {
            this.originalRow = originalRow;
            this.originalColumn = originalColumn;
            this.color = color;
        }

        protected void WriteAt(string s, int x, int y)
        {
            ConsoleColor localcolor = Console.ForegroundColor;

            if (color != null)
            {
                Console.ForegroundColor = (ConsoleColor)color;
            }
            try
            {
                Console.SetCursorPosition(originalColumn + x, originalRow + y);
                Console.Write("{0}", s);
            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.Clear();
                Console.WriteLine(e.Message);
            }
            if (color != null)
            {
                Console.ForegroundColor = localcolor;
            }
        }

        protected void WriteAt(int n, int x, int y, int precision)
        {

            ConsoleColor localcolor = Console.ForegroundColor;

            if (color != null)
            {
                Console.ForegroundColor = (ConsoleColor)color;
            }
            string formatString = string.Format("{{0:D{0}}}", precision);
            try
            {
                Console.SetCursorPosition(originalColumn + x, originalRow + y);
                Console.Write(formatString, n);
            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.Clear();
                Console.WriteLine(e.Message);
            }

            if (color != null)
            {
                Console.ForegroundColor = localcolor;
            }

        }
    }
}
