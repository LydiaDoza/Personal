using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace ReflectionDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            string assemblyName = @"C:\Users\Lydia\Documents\GitHub\Personal\Patterns\Reflection\ReflectionDemo\ReflectionDemo\Calc\bin\Debug\Calc.dll";
            Assembly assembly = Assembly.LoadFrom(assemblyName);

            Type[] types = assembly.GetTypes();

            Console.WriteLine("the types available in assembly {0} are:", assembly);
            Console.WriteLine("__________");

            foreach (Type type in types)
            {
                Console.WriteLine("The class name is: {0}", type.FullName);
                Console.WriteLine("The namespace is: {0}", type.Namespace);
                Console.WriteLine("The base type is: {0}", (type.BaseType != null) ?
                    type.BaseType.FullName : "There is not basetype");
                Console.WriteLine("__________");

                foreach (MethodInfo methodInfo in type.GetMethods(BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly))
                {
                    Console.WriteLine("The method signature is: {0}", methodInfo);

                    foreach (ParameterInfo parameter in methodInfo.GetParameters())
                    {
                        Console.WriteLine("The parameter type is: {0}, The parameter name is: {1}", parameter.ParameterType, parameter.Name);
                    }
                    Console.WriteLine("__________");

                    Console.WriteLine("Dynamically calling method {0} on {1}", methodInfo.Name, type.FullName);

                    object dInstance = Activator.CreateInstance(type);
                    object[] arguments = { 5, 10 };
                    object result;

                    result = type.InvokeMember(methodInfo.Name, BindingFlags.InvokeMethod,
                        null, dInstance, arguments);
                    Console.WriteLine("The result is: {0}", result);
                }
            }

            Console.Read();
        }
    }
}
