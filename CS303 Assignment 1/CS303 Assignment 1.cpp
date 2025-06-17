// CS303 Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	minValue();
	minIndex();
	maxValue();
	// maxIndex();
	IntExists(OutFile);

	modify_value(OutFile);
	int n = 100;

	cout << "\n\nARRAY BEFORE INSERTION \n";
	OutFile << "\n\nARRAY BEFORE INSERTION \n";
	displayArr(arr, n, OutFile);


	cout << "\nPlease enter an element to insert at the end of the array:  ";
	OutFile << "\nPlease enter an element to insert at the end of the array:  ";
	int e = 0;
	cin >> e;
	OutFile << e << endl;
	insertAtEnd(arr, n, e, OutFile);
	

	cout << "\n\nARRAY AFTER INSERTION \n";
	OutFile << "\n\nARRAY AFTER INSERTION \n";

	displayArr(arr, n, OutFile);

	removeElement(arr, 0, OutFile);
	
	OutFile << " \n\n=========== Output file Close  ===========\n";

	// Close the output file
	OutFile.close();
	return 0;
	
}

