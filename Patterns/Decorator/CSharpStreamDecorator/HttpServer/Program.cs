using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.IO;
using System.Threading;

namespace HttpServer
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Started");
            HttpListener listener = new HttpListener();

            listener.Prefixes.Add("http://localhost:8888/decorator/");

            listener.Start();

            while (true)
            {
                HttpListenerContext ctx = listener.GetContext();
                Console.WriteLine("connected");
                ProcessRequest(ctx);
            }
        }

        private static void ProcessRequest(HttpListenerContext ctx)
        {
            using (StreamWriter w = new StreamWriter(ctx.Response.OutputStream))
            {
                for (int i = 0; i < 100; i++)
                {
                    int rand = new Random().Next(1000);

                    Console.WriteLine("sleep {0}", rand);
                    Thread.Sleep(rand);

                    WriteData(w);
                }
            }
        }

        private static void WriteData(StreamWriter w)
        {
            int rand = new Random().Next(20480);

            Console.WriteLine("datasize {0}", rand);
            char[] data = new char[rand];
            for (int i = 0; i < rand; i++)
                data[i] = (char)(i % 255);

            w.Write(data);
            w.Flush();
        }
    }
}
