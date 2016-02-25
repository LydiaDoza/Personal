namespace ExternalCompositeIterator2016
{
    public interface IVisitor
    {
        void Visit(CompanyComposite composite);
        void Visit(Employee employee);
    }
}