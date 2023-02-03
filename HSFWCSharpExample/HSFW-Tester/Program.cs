using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OptecHID_FilterWheelAPI;

namespace HSFW_Tester
{
	internal class Program
	{
		static void Main(string[] args)
		{
			FilterWheels filterWheels = new FilterWheels();

			Console.WriteLine("Searching for FilterWheels");
			foreach (FilterWheel wheel in filterWheels.AttachedFilterWheels)
			{
				Console.WriteLine($"{wheel.Name}, Serial Number: {wheel.SerialNumber}, Firmware Version: {wheel.FirmwareVersion}");
			}


			if (filterWheels.AttachedFilterWheels.Count() > 0)
			{
				Console.WriteLine("Using wheel");
				var wheel = filterWheels.AttachedFilterWheels.First();

				Console.WriteLine($"{wheel.Name}, Serial Number: {wheel.SerialNumber}, Firmware Version: {wheel.FirmwareVersion}");

				//Clear any Errors
				wheel.ClearErrorState();

				//Home wheel
				wheel.HomeDevice();

				//Print Names
				foreach (var filter in wheel.GetWheelNames())
				{
					Console.WriteLine(filter);
				}

				//Move the wheel
				for (short i = 1; i<wheel.NumberOfFilters + 1; i++)
				{
					Console.WriteLine($"Starting move from {wheel.CurrentPosition} to {i}");
					wheel.CurrentPosition = i;
					Console.WriteLine($"Moved to {wheel.CurrentPosition}");
				}

			}
			else
			{
				Console.WriteLine("No Filter Wheels Attached");
			}
			Console.ReadLine();
		}
	}
}
