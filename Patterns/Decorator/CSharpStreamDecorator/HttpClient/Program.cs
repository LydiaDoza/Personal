using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.IO;

namespace HttpClient
{
    class Program
    {
        static void Main(string[] args)
        {
            WebRequest request = WebRequest.Create("http://localhost:8888/decorator");

            WebResponse response = request.GetResponse();

            Stream responseStream = response.GetResponseStream();

            responseStream = new BandWidthDecorator(responseStream);

            responseStream = new PauseResumeDecorator(responseStream);

            WriteFile(responseStream, @"downloadFile.bin");
        }

        private static void WriteFile(Stream stream, string fileName)
        {
            Stream outputStream = File.Create(fileName);

            byte[] buffer = new byte[10 * 1024];

            int bytesRead = 0;
            while ((bytesRead = stream.Read(buffer, 0, buffer.Length)) > 0)
            {
                outputStream.Write(buffer, 0, bytesRead);
            }
        }
    }
}
