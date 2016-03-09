using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StateLabBankAccount
{
    public partial class StateBankAccount
    {
        private double Balance { get; set; }

        AbstractAccountState _state;

        ConfirmingIdentity _confirmingIdentity;
        AccountActive _accountActive;
        Frozen _frozen;
        Closing _closing;
        Closed _closed;

        public StateBankAccount()
        {
            _confirmingIdentity = new ConfirmingIdentity(this);
            _accountActive = new AccountActive(this);
            _frozen = new Frozen(this);
            _closing = new Closing(this);
            _closed = new Closed(this);

            Balance = 0.0;
            _state = _confirmingIdentity;
        }

        public void IdentityConfirmed(string pin)
        {
            _state.IdentityConfirmed(pin);
        }

        public void Credit(double amount)
        {
            _state.Credit(amount);
        }

        public void Debit(double amount)
        {
            _state.Debit(amount);
        }

        public void Freeze()
        {
            _state.Freeze();
        }

        public void Unfreeze()
        {
            _state.Unfreeze();
        }

        public void Close()
        {
            _state.Close();
        }

        private void InternalCredit(double amount)
        {
            Balance += amount;
            Console.WriteLine("Credit {0:C} current balance is {1:C} ", 
                amount, Balance);
        }

        private void InternalDebit(double amount)
        {
            Balance -= amount;
            Console.WriteLine("Debit {0:C} current balance is {1:C} ", 
                amount, Balance);

        }

        private void InternalFreeze()
        {
            Console.WriteLine("Freezing Account");
        }

        private void InternalUnfreeze()
        {
            Console.WriteLine("Unfreezing Account");
        }

        private void InternalClose()
        {
            if (Balance == 0)
            {
                Console.WriteLine("Balance is $0.0, account closed");
                MessageBox.Show("Balance is $0.0, account closed");
            }
            else
            {
                Console.WriteLine("Check for {0:C} is in the mail, account closed", Balance);
                MessageBox.Show($"Check for {Balance:C} is in the mail, account closed");
            }
        }

        private void InternalClosingOverdrawn()
        {
            Console.WriteLine("You can't close an overdrawn amount, current balance is: {0:C} ", Balance);
            MessageBox.Show($"You can't close an overdrawn amount, current balance is: {Balance:C} ");
        }

        private void InternalUnconfirmedIdentity()
        {
            Console.WriteLine("Identity not confirmed, account closing");
        }
    }
}
