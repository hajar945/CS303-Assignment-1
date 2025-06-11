#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of


using namespace std;

// Function to read data from a file into an array

// https://stackoverflow.com/questions/47426692/read-data-from-a-file-into-an-array-c
const int SIZE = 100;
int arr[SIZE];

void readData() {

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
	OutFile << "This is the output file." << endl;



	string inFileName = "A1input.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < SIZE; i++)
		{
			inFile >> arr[i];
			cout << "Element at index '" << i << "' is " << arr[i] << ".\n";
			// OutFile << "Element at index '" << i << "' is " << arr[i] << ".\n";
		}

		inFile.close(); // CLose input file
	}
	else { //Error message
		cerr << "Can't find input file " << inFileName << endl;
	}
	// Close the output file
	OutFile.close();
}



int minValue() { // https://stackoverflow.com/questions/66677428/how-do-i-find-the-smallest-element-of-an-array-in-c
	int size = sizeof(arr) / sizeof(arr[0]);
	int minval = arr[0];
	int index = 0;

	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < minval)
		{
			index = i;
			minval = arr[i];
		}
	}
	cout << "\n\nMinimum value is [" << minval << "] at index " << index << endl;
	return minval;
}


int maxValue() { 
	int size = sizeof(arr) / sizeof(arr[0]);
	int maxval = arr[0];
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (arr[i] > maxval)
		{
			index = i;
			maxval = arr[i];
		}
	}
	cout << "\n\Maximum value is [" << maxval << "] at index " << index << endl;
	return maxval;
}

int minIndex() {
	int size = sizeof(arr) / sizeof(arr[0]);
	int minidx = arr[0];
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (i < minidx)
		{
			minidx = i;
		}
	}
	cout << "\n\nSMALLEST *INDEX* is [" << minidx << "] with Element " << arr[minidx] << endl;
	return minidx;
}

int maxIndex() {
	int size = sizeof(arr) / sizeof(arr[0]);
	int maxidx = arr[0];
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (i > maxidx)
		{
			maxidx = i;
		}
	}
	cout << "\n\GREATEST *INDEX* is [" << maxidx << "] with Element " << arr[maxidx] << endl;
	return maxidx;
}


bool ValidInput() {
	
	int minval = minValue();
	int index = 0;
	int val = 0;
	val = arr[index];

	cout << "\nAs of now, the arr[index] is " << arr[index]
		<< "\n And the index is currently = " << index << endl;

	cout << "The size  of the ARRAY is " << SIZE << endl;


	do {
		cout << "\n\nPlease enter an index between " << minval << " and " << arr[index - 1] << " :\n";
		cin >> index;
	} while (index < 0 || index >= SIZE || index == NULL);
	try {
		if (index >= 0 && index < SIZE) {
			cout << "You have entered a valid index: " << index << endl <<
				"Its value is [" << arr[index] << "]" << endl;
			return true;

		}
		else {
			throw out_of_range("Index is out of bounds 'else block'.");
		}
	}
	catch (const exception& e) {
		cerr << "Invalid input: " << e.what() << endl;
		return false;
	}
}


int modint() {

}