// CS303 Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of
#include <limits>

#include "Functions.h"

using namespace std;

int main()
{
	


	readData();
	
	minValue();
	minIndex();
	maxValue();
	maxIndex();
	ValidInput();

	return 0;

    
}

