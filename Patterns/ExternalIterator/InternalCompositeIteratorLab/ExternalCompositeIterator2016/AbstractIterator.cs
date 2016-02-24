namespace ExternalCompositeIterator2016
{
    public abstract class AbstractIterator
    {
        protected CompanyComponent inner;
        protected int current;

        public abstract void First();
        public abstract void MoveNext();
        public abstract bool IsDone();
        public abstract CompanyComponent GetCurrent();
    }
}
