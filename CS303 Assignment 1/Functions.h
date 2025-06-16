#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of
#include <iterator>


using namespace std;

// Function to read data from a file into an array

// https://stackoverflow.com/questions/47426692/read-data-from-a-file-into-an-array-c
const int SIZE = 101; // 101 for the extra space for adding an element at the end of the array
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

bool IntExists() {

	int index = 0;
	int val = 0;
	val = arr[index];


	do { 
		try { // https://www.geeksforgeeks.org/exception-handling-c/
			cout << "Please enter an index to view its element:  ";
			cin >> index;


			if (index < 0 || index >= SIZE) {
				cout << "\n\nInvalid index [" << index << "]. Please enter a valid index between 0 and "
					<< SIZE - 1 << ".\n";
				throw out_of_range("Out of range");
			}
			if (index == NULL) {
				cout << "\n\nNULL input is not allowed. Please enter a valid index.\n";
				throw invalid_argument("Input cannot be null");

			}

		}
		// executed when exception is of type out_of_range
		catch (out_of_range e) {
			cout << "Caught exception: " << e.what() << endl;
		}
		// executed when exception is type invalid_argument
		catch (invalid_argument e) {
			cout << "Caught exception: " << e.what() << endl;
		}

	} while (!(index > 0 && index < SIZE && index != NULL));


	if ((index > 0 && index < SIZE && index != NULL))
		cout << "VALID INDEX [" << index << "] with Element " << arr[index] << endl;
	return index;
	return true;
}


bool ValidInput(int& index) {
//	int index = 0;
	int val = 0;
	val = arr[index];

	do {
		cout << "Please enter an index:  ";
		cin >> index;

		if (index < 0 || index >= SIZE) {
			cout << "Invalid index [" << index << "]. Please enter a valid index between 0 and 99.\n";
		}
		if (index == NULL) {
			cout << "NULL input is not allowed. Please enter a valid index.\n";
		}
		
	} while (!(index > 0 && index < SIZE && index != NULL));
	if ((index > 0 && index < SIZE && index != NULL))
		cout << "VALID INDEX [" << index << "]\n\n";
	return index;
	return true;
}




// (QUESTION 2) Function to change an element at an index and display the old and new values
int modify_value() {

	int oldIndex = 0;
	int oldValue = 0;
	int newIndex = 0;
	int newValue;

	do {
		try {
			cout << "\nPlease enter an index to change its element: ";
			cin >> oldIndex;

			if (oldIndex < 0 || oldIndex >= SIZE - 1) {
				cout << "\nInvalid index [" << oldIndex << "]. Please enter a valid index from 0 to 99.\n";
				throw out_of_range("Out of range");
			}
			else if (oldIndex == NULL) {
				cout << "\nNULL input is not allowed. Please enter a valid index.\n";
				throw invalid_argument("Input cannot be null");
			}
		}
		// executed when exception is of type out_of_range
		catch (out_of_range e) {
			cout << "Caught exception: " << e.what() << endl;
		}
		// executed when exception is type invalid_argument
		catch (invalid_argument e) {
			cout << "Caught exception: " << e.what() << endl;
		}

	} while (!(oldIndex >= 0 && oldIndex < SIZE-1 && oldIndex != NULL)); // Ensure valid index input
		if ((oldIndex > 0 && oldIndex < SIZE-1 && oldIndex != NULL))
			cout << "\nValid index [" << oldIndex << "]\n\n";


	cout << "To what INTEGER would you like to change the element to? ";
	cin >> newValue;
	oldValue = arr[oldIndex];

	arr[oldIndex] = newValue; // Change the value at the specified index

	cout << "\nBEFORE\n Index = " << oldIndex << "\n Element = " << oldValue << endl;
	cout << "\nAFTER\n Index = " << oldIndex << "\n Element = " << newValue << endl;


	return newValue;
}



// Function to display the array elements
void displayArr(int arr[], int n) { // https://www.tutorialspoint.com/cplusplus-program-to-append-an-element-into-an-array
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

// (QUESTION 3) Function to insert an element at the end of the array
void insertAtEnd(int arr[], int& n, int e) { // https://www.tutorialspoint.com/cplusplus-program-to-append-an-element-into-an-array

	try {

		if (e < 0) {
			cout << "\nInvalid element. Please enter a positive integer.\n";
			throw out_of_range("Out of range");
			std::cin.clear(); // Clear the error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
		}
		else if (e == 0) {
			cout << "\nInvalid element. Please enter an integer greater than 0.\n";
			throw out_of_range("Out of range");
			std::cin.clear(); // Clear the error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
		}
		
	}
	// executed when exception is of type out_of_range
	catch (out_of_range e) {
		cout << "Caught exception: " << e.what() << endl;
	}

	if (n < SIZE) {
		arr[n] = e;
	}
	n = n + 1;
}



void removeElement(int arr[], int key) { // https://stackoverflow.com/questions/879603/remove-an-array-element-and-shift-the-remaining-ones
	cout << "\nPlease enter an index to remove its element:  ";
	cin >> key;

	// delete element at index key
	for (int i = key; i < SIZE; ++i)
		arr[i] = arr[i + 1]; // copy next element left


	copy(arr + key, // copy everything starting here
		arr + SIZE, // and ending here, not including it,
		arr + key); // to this destination
	

	auto arrayEnd = remove(arr, arr + SIZE, 0);

	// Calculate the new size after removal
	int ns = arrayEnd - arr; // https://www.geeksforgeeks.org/std-remove-algorithm-in-cpp/
	for (int i = 0; i < ns; i++)
		cout << arr[i] << " ";


}