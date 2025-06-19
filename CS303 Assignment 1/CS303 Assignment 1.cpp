// CS303 Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Hajar Wilkes
// Comp-Sci 303 Spring 2025

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of
#include <limits>
#include <iterator>

#include "Functions.h"

using namespace std;


int main()
{
	//using ofstream for output file operations.
	ofstream OutFile;
	// Opening file "Out.txt" in write mode.
	OutFile.open("Out.txt");


	// Check if the file was successfully created.
	if (!OutFile.is_open())
	{
		cout << "Error in creating file!" << endl;

	}
	cout << "Output File created successfully." << endl;


	readData(OutFile);

	// Display the menu 
	menu1(OutFile);

	OutFile << " \n\n=========== Output file Close  ===========\n";

	// Close the output file
	OutFile.close();
	return 0;

}