using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Management;
using System.IO.Ports;
using System.Threading;

namespace Arduino_Computer
{
    class Program
    {
        /*
            This code showed me how to communcate with the serial port.
            https://www.c-sharpcorner.com/UploadFile/eclipsed4utoo/communicating-with-serial-port-in-C-Sharp/
            https://docs.microsoft.com/en-us/dotnet/api/system.io.ports.serialport?view=dotnet-plat-ext-5.0

            this code helped with the do while loop
            https://docs.microsoft.com/en-us/dotnet/api/system.console.keyavailable?view=net-5.0

        */


        static void Main(string[] args)
        {
            //sets the amount of seconds between sending memory usage
            int milliseconds = 10000;
            //set the serial port and its informations
            SerialPort _serialPort = new SerialPort("COM7", 9600);
            int perMemoryUsed;
            //Creating a MemoryInfo object that will collect the information needed to output
            MemoryInfo info = new MemoryInfo();

            //Open the serial port to connect to it
            _serialPort.Open();

            //Message to tell the user how to exit the program
            Console.WriteLine("Press ESC to stop");
       
            do
            {
                while (!Console.KeyAvailable)
                {
                    //Grab and convert the double that is generated by the GetMemory function
                    //and round it up by converting it to an integer
                    perMemoryUsed = Convert.ToInt32(info.GetMemory());
                    Console.WriteLine("Collected Memory Used: "+ perMemoryUsed  + "% of Ram Used");
                    try
                    {
                        //As long as the serial port is open the program will attempt to 
                        //Send the memory usage out
                        if (!(_serialPort.IsOpen))
                            _serialPort.Open();
                        _serialPort.WriteLine(perMemoryUsed + "% of mem used");
                        Console.WriteLine("Sent amount of ram used");
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine("Error opening/writing to serial port :: " + ex.Message, "Error!");
                    }
                    Thread.Sleep(milliseconds);

                }
                //This will all happen as long as the ESC key is not pressed which will exit the loop
            } while (Console.ReadKey(true).Key != ConsoleKey.Escape);




        }
    }
}
