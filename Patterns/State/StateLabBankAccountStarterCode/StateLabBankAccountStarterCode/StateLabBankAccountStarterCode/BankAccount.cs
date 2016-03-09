using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StateLabBankAccountStarterCode
{
    class BankAccount
    {
        enum AccountStates
        {
            CONFIRMING_IDENTITY,
            ACCOUNT_ACTIVE,
            FROZEN,
            CLOSING,
            CLOSED
        }

        double balance;
        AccountStates state;

        public BankAccount()
        {
            state = AccountStates.CONFIRMING_IDENTITY;
        }

        double Balance
        {
            get { return balance; }
            set { balance = value; }
        }

        public void IdentityConfirmed(string pin)
        {
            if (state != AccountStates.CONFIRMING_IDENTITY)
            {
                throw new InvalidOperationException("ConfirmingIdentity");
            }

            if (pin == "1234")
            {
                state = AccountStates.ACCOUNT_ACTIVE;
            }
            else
            {
                Close();
            }
        }

        public void Credit(double amount)
        {
            if (state != AccountStates.ACCOUNT_ACTIVE && state != AccountStates.CLOSING)
            {
                throw new InvalidOperationException("Credit");
            }

            balance += amount;

            Console.WriteLine("Credit {0:C} current balance is {1:C} ", amount, balance);

        }

        public void Debit(double amount)
        {
            if (state != AccountStates.ACCOUNT_ACTIVE)
            {
                throw new InvalidOperationException("Debit");
            }

            balance -= amount;
            Console.WriteLine("Debit {0:C} current balance is {1:C} ", amount, balance);

        }

        public void Freeze()
        {
            if (state != AccountStates.ACCOUNT_ACTIVE)
            {
                throw new InvalidOperationException("Freeze");
            }

            Console.WriteLine("Freezing Account");
            state = AccountStates.FROZEN;
        }

        public void Unfreeze()
        {
            if (state != AccountStates.FROZEN)
            {
                throw new InvalidOperationException("Unfreeze");
            }

            Console.WriteLine("Unfreezing Account");
            state = AccountStates.ACCOUNT_ACTIVE;
        }

        public void Close()
        {

            if ((state == AccountStates.ACCOUNT_ACTIVE) || (state == AccountStates.CLOSING))
            {
                if (balance == 0)
                {
                    Console.WriteLine("Balance is $0.0, account closed");
                    MessageBox.Show("Balance is $0.0, account closed");
                    state = AccountStates.CLOSED;
                }
                else if (balance > 0)
                {
                    Console.WriteLine("Check for {0:C} is in the mail, account closed", balance);
                    MessageBox.Show(String.Format("Check for {0:C} is in the mail, account closed", balance));
                    state = AccountStates.CLOSED;
                }
                else
                {
                    Console.WriteLine("You can't close an overdrawn amount, current balance is: {0:C} ", balance);
                    MessageBox.Show(String.Format("You can't close an overdrawn amount, current balance is: {0:C} ", balance));
                    state = AccountStates.CLOSING;
                }
            }
            else if (state == AccountStates.CONFIRMING_IDENTITY)
            {
                Console.WriteLine("Identity not confirmed, account closing");
                state = AccountStates.CLOSED;
            }
            else
            {
                throw new InvalidOperationException("Close");
            }
        }
    }
}
