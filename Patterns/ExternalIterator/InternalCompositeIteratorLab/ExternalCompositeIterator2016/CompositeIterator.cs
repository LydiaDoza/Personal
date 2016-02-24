using System;
using System.Collections.Generic;

namespace ExternalCompositeIterator2016
{
    public class CompositeIterator : AbstractIterator
    {
        Stack<AbstractIterator> _stack = new Stack<AbstractIterator>();

        public CompositeIterator(CompanyComponent component)
        {
            inner = component;
            inner.NodeDisplay();
            _stack.Push(inner.CreateIterator());
            current = 0;
        }

        public override void First()
        {
            _stack.Peek().First();
        }

        public override void MoveNext()
        {
            if (_stack.Peek().GetCurrent() is CompanyComposite)
                _stack.Push(_stack.Peek().GetCurrent().CreateIterator());
            else
                _stack.Peek().MoveNext();
        }

        public override bool IsDone()
        {
            if (_stack.Count == 0)
                return true;
            else
            {
                if (_stack.Peek().IsDone())
                {
                    _stack.Pop();

                    if (_stack.Count != 0)
                        _stack.Peek().MoveNext();

                    return IsDone();
                }
                return false;
            }
        }

        public override CompanyComponent GetCurrent()
        {
            if (IsDone())
            {
                throw new Exception("There is nothing in iterator");
            }

            return _stack.Peek().GetCurrent();
        }
    }
}
