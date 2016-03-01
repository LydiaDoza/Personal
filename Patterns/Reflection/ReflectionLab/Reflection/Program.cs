using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Reflection;

namespace Reflection
{
    class Program
    {
        static void Main(string[] args)
        {
            string assemblyName = @"..\..\..\ReflectionLab\bin\Debug\ReflectionLab.dll";
            Assembly assembly = Assembly.LoadFrom(assemblyName);

            Type[] types = assembly.GetTypes();

            Console.WriteLine("The types Available in assembly {0} are: ", assembly);
            Console.WriteLine("________________");


            foreach (Type type in types)
            {
                Console.WriteLine();
                Console.WriteLine("The Class Name is:   {0}", type.FullName);
                Console.WriteLine("The namespace is:    {0}", type.Namespace);
                Console.WriteLine("The base type is:    {0}",
                    (type.BaseType != null) ? type.BaseType.FullName : "There is no base type.");
                Console.WriteLine("________________");

                //BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly)
                foreach (MethodInfo methodInfo in type.GetMethods(BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly))
                {
                    Console.WriteLine();
                    Console.WriteLine("The Method Signature is: {0}", methodInfo);

                    foreach (ParameterInfo parameter in methodInfo.GetParameters())
                    {
                        Console.WriteLine("  The parameter type is {0}, ", parameter.ParameterType);
                        Console.WriteLine("  The parameter name is {0}", parameter.Name);
                    }
                    Console.WriteLine("    _____________   ");

                    Console.WriteLine("Dynamically calling method {0} on {1}", methodInfo.Name, type.FullName);
                    object dInstance = Activator.CreateInstance(type);

                    if (methodInfo.GetParameters().Length != 0)
                    {
                        object[] arguments = { "Bob", "address", 1234567890 };
                        object result = type.InvokeMember(methodInfo.Name, BindingFlags.InvokeMethod,
                        null, dInstance, arguments);
                        Console.WriteLine("The result is: {0}", result);

                    }
                    else
                    {
                        object[] arguments = { };
                        object result = type.InvokeMember(methodInfo.Name, BindingFlags.InvokeMethod,
                            null, dInstance, arguments);
                        Console.WriteLine("The result is: {0}", result);

                    }
                    Console.WriteLine("________________");

                }
            }

            Console.Read();
        }
    }
}
