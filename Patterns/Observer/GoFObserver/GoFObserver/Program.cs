using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoFObserver
{
    class Program
    {
        static void Main(string[] args)
        {
            IStudentObserver Breedlove = new Professor();
            IStudentObserver Jane = new Spouse();

            Student Cal = new Student();
            Cal.Attach(Breedlove);
            Cal.Attach(Jane);

            Cal.DoWork();
        }
    }
}
