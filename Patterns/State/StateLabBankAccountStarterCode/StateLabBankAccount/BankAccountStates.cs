using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StateLabBankAccount
{
    public partial class StateBankAccount
    {
        public class ConfirmingIdentity : AbstractAccountState
        {
            public ConfirmingIdentity(StateBankAccount acc) : base(acc)
            { }

            public override void IdentityConfirmed(string pin)
            {
                if (pin == "1234")
                    _account._state = _account._accountActive;
                else
                    _account._state.Close();
            }

            public override void Close()
            {
                _account.InternalUnconfirmedIdentity();
                _account._state = _account._closed;
            }
        }

        public class AccountActive : AbstractAccountState
        {
            public AccountActive(StateBankAccount acc) : base(acc)
            { }

            public override void Credit(double amount)
            {
                _account.InternalCredit(amount);
            }

            public override void Debit(double amount)
            {
                _account.InternalDebit(amount);
            }

            public override void Freeze()
            {
                _account.InternalFreeze();
                _account._state = _account._frozen;
            }

            public override void Close()
            {
                if (_account.Balance >= 0)
                {
                    _account.InternalClose();
                    _account._state = _account._closed;
                }
                else
                {
                    _account.InternalClosingOverdrawn();
                    _account._state = _account._closing;
                }
            }
        }

        public class Frozen : AbstractAccountState
        {
            public Frozen(StateBankAccount acc) : base(acc)
            { }

            public override void Unfreeze()
            {
                _account.InternalUnfreeze();
                _account._state = _account._accountActive;
            }
        }

        public class Closing : AbstractAccountState
        {
            public Closing(StateBankAccount acc) : base(acc)
            { }

            public override void Credit(double amount)
            {
               _account.InternalCredit(amount);
            }

            public override void Close()
            {
                if (_account.Balance >= 0)
                {
                    _account.InternalClose();
                    _account._state = _account._closed;
                }
                else
                {
                    _account.InternalClosingOverdrawn();
                    // _account._state = _account._closing;
                    // already in closing state
                }
            }
        }

        public class Closed : AbstractAccountState
        {
            public Closed(StateBankAccount acc) : base(acc)
            { }
        }
    }
}
