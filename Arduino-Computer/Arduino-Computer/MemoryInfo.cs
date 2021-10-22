using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Diagnostics;
using System.Management;
using System.Linq;

namespace Arduino_Computer
{
   
    class MemoryInfo 
    {

        //https://stackoverflow.com/questions/10027341/c-sharp-get-used-memory-in
        //This is were I got the code for the memory information gathering
        public double GetMemory()
        {
            //This grabs infomation from the operating system
            var wmiObject = new ManagementObjectSearcher("select * from Win32_OperatingSystem");

            //This uses the wmiObject and queryiest it to get the free physical memory,
            //and total visible memory
            var memoryValues = wmiObject.Get().Cast<ManagementObject>().Select(mo => new {
                FreePhysicalMemory = Double.Parse(mo["FreePhysicalMemory"].ToString()),
                TotalVisibleMemorySize = Double.Parse(mo["TotalVisibleMemorySize"].ToString())
            }).FirstOrDefault();


            if (memoryValues != null)
            {
                return GetPercentage(memoryValues.TotalVisibleMemorySize, memoryValues.FreePhysicalMemory);
            }

            return -1;
        }

        //This gets the percentage of memory
        //used by using the total and what was not used
        public double GetPercentage(double total, double notUsed)
        {
            double percent;

            double memoryLeft = total - notUsed;

            percent = (memoryLeft / total) * 100;

            return percent;
        }

    }
}
