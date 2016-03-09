using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StateLabBankAccount
{
    public abstract class AbstractAccountState
    {
        protected StateBankAccount _account;
        public AbstractAccountState(StateBankAccount acc)
        {
            _account = acc;
        }

        public virtual void IdentityConfirmed(string pin)
        {
            throw new InvalidOperationException("IdentityConfirmed");
        }

        public virtual void Credit(double amount)
        {
            throw new InvalidOperationException("Credit");
        }

        public virtual void Debit(double amount)
        {
            throw new InvalidOperationException("Debit");
        }

        public virtual void Freeze()
        {
            throw new InvalidOperationException("Freeze");
        }

        public virtual void Unfreeze()
        {
            throw new InvalidOperationException("Unfreeze");
        }

        public virtual void Close()
        {
            throw new InvalidOperationException("Close");
        }
    }
}
