// HSFWCppConsoleExample.cpp : main project file.

#include "stdafx.h"

#include <iostream>

using namespace System;
using namespace OptecHID_FilterWheelAPI;

int main(array<System::String ^> ^args)
{
	FilterWheels^ myFilterWheelManager;
	try{
		myFilterWheelManager = gcnew FilterWheels();
	}
	catch (...){

	}
	FilterWheel^ HSFW;
	//Lists all the filter wheels attached
	//Grabs the last one (if there is only one grabs that one)
	for each (FilterWheel ^ FW in myFilterWheelManager->FilterWheelList){
		HSFW = FW;
	}

	//Check for no filterwheels
	if (!HSFW){
		std::cout << "There are no filter wheels currently attached." << "\n";
		std::cout << "Press enter to continue: \n";
		std::getchar();
		return 0;
	}
	//Clear any errors
	HSFW->ClearErrorState();
	//Check for more then one HSFW
	try
	{
		if (myFilterWheelManager->AttachedDeviceCount == 0)
		{
			std::cout << "There are no filter wheels currently attached." << "\n";
		}
		else{
			std::cout << "There number of filter wheels currently attached is: " << myFilterWheelManager->AttachedDeviceCount << "\n";
			std::cout << "Press enter to continue: \n";
			std::getchar();
		}
	}
	catch (...){
		std::cout << "There are no filter wheels currently attached." << "\n";
		return 0;
	}

	if (HSFW->IsAttached)
	{
		std::cout << "Homing device\n";

		HSFW->HomeDevice();
		while (HSFW->IsHoming){
				//wait for home to finish
		}
		std::cout << "Device is homed? " << HSFW->IsHomed <<" \n";
		std::cout << "Press enter to continue: \n";
		std::getchar();

		short i = HSFW->NumberOfFilters;

		//move to max filter

		std::cout << "The current position is: " << HSFW->CurrentPosition << "\n";
		std::cout << "Moving to: " << i << "\n";
		HSFW->CurrentPosition = i;
		std::cout << "The current position is: " << HSFW->CurrentPosition << "\n";
		std::cout << "Press enter to continue: \n";
		std::getchar();

		std::cout << "The current position is: " << HSFW->CurrentPosition << "\n";
		std::cout << "Moving to: " << 1 << "\n";
		HSFW->CurrentPosition = 1;
		std::cout << "The current position is: " << HSFW->CurrentPosition << "\n";
		std::cout << "Press enter to continue: \n";
		std::getchar();

		std::cout << "C++ tests done, press enter to continue: \n";
		std::getchar();
		return 1;
	}
}