using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using StateLabBankAccount;

namespace Doza
{
    class Program
    {
        private static void ConfirmingIdentityTest()
        {
            StateBankAccount bankaccount = new StateBankAccount();
            bankaccount.IdentityConfirmed("2345");
        }

        private static void PassTestStates()
        {
            StateBankAccount bankaccount = new StateBankAccount();
            bankaccount.IdentityConfirmed("1234");
            bankaccount.Credit(1000);
            bankaccount.Credit(1000);
            bankaccount.Credit(1000);
            bankaccount.Freeze();
            bankaccount.Unfreeze();
            bankaccount.Debit(3000);
            bankaccount.Close();
        }

        private static void OtherTestStates()
        {
            StateBankAccount bankaccount = new StateBankAccount();
            bankaccount.IdentityConfirmed("1234");
            bankaccount.Credit(1000);
            bankaccount.Credit(1000);
            bankaccount.Debit(1000);
            bankaccount.Freeze();

            //Note: For each test below, uncomment a test and check your results. Then
            //comment out that test and move to the next test.

            //Test #1: Invalid state for debit should throw an exception
            bankaccount.Debit(1000);

            bankaccount.Unfreeze();

            //Test #2: Account closes properly with zero balance
            bankaccount.Debit(1000);

            // Test #3 : Overdraws account account can't be closed
            //bankaccount.Debit(2500);

            //Initial run, balance not zero, cuts a check and closes account
            bankaccount.Close();

            //Test #4 : Leave Test #3 uncommented. Credits 1500 and can now close the account
            //bankaccount.Credit(1500);
            //bankaccount.Close();
        }

        static void Main(string[] args)
        {
            //PassTestStates();
            //ConfirmingIdentityTest(); //Invalid Identity Test
            OtherTestStates();
        }
    }
}
