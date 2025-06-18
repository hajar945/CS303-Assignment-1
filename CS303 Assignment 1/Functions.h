#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of
#include <limits>
#include <iterator>


using namespace std;

// Function to read data from a file into an array

// https://stackoverflow.com/questions/47426692/read-data-from-a-file-into-an-array-c
const int SIZE = 200; // 101 for the extra space for adding an element at the end of the array
int arr[SIZE];


void readData(ofstream& OutFile) {


	

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


	
}


int num_of_elements() {
	auto last = std::find(std::begin(arr), std::end(arr), 0);

	auto num_items = std::distance(std::begin(arr), last);

	cout << "\n\nNumber of elements in the array is: " << num_items << endl;
	return num_items;
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

bool IntExists(ofstream& OutFile) {

	int index = 0;
	int val = 0;
	val = arr[index];


	do { 
		try { // https://www.geeksforgeeks.org/exception-handling-c/
			cout << "Please enter an index to view its element:  ";
			OutFile << "Please enter an index to view its element:  ";

			cin >> index;
			OutFile << index << endl;


			if (index < 0 || index >= SIZE) {
				cout << "\n\nInvalid index [" << index << "]. Please enter a valid index between 0 and "
					<< SIZE - 1 << ".\n";
				OutFile << "\n\nInvalid index [" << index << "]. Please enter a valid index between 0 and "
					<< SIZE - 1 << ".\n";
				throw out_of_range("Out of range");
			}
	

		}
		// executed when exception is of type out_of_range
		catch (out_of_range e) {
			cout << "Caught exception: " << e.what() << endl;
			OutFile << "Caught exception: " << e.what() << endl;

		}

	} while (!(index >= 0 && index < SIZE));


	if ((index >= 0 && index < SIZE))
		cout << "VALID INDEX [" << index << "] with Element " << arr[index] << endl;
	OutFile << "VALID INDEX [" << index << "] with Element " << arr[index] << endl;

	return index;
	return true;
}


bool ValidInput(ofstream& OutFile) {
	int index = -1;
	while (true) {
		try {
			std::cout << "\nPlease enter an index between 0 and " << (SIZE - 1) << ": ";
			OutFile << "\nPlease enter an index between 0 and " << (SIZE - 1) << ": ";

			if (!(std::cin >> index)) {
				// Non-integer input
				throw std::invalid_argument("Input is not a valid integer.");
			}
			if (index < 0 || index >= SIZE) {
				// Out-of-range integer
				throw std::out_of_range("Index is out of valid range.");
			}
			// If we get here, it's valid
			std::cout << "You entered index " << index
				<< " (value = " << arr[index] << ")\n";
			OutFile << "You entered index " << index
				<< " (value = " << arr[index] << ")\n";
			return true;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Invalid input: " << e.what() << "\n";
			OutFile << "Invalid input: " << e.what() << "\n";

		}
		catch (const std::out_of_range& e) {
			std::cerr << "Invalid input: " << e.what()
				<< " (must be 0 to " << (SIZE - 1) << ")\n";
			OutFile << "Invalid input: " << e.what()
				<< " (must be 0 to " << (SIZE - 1) << ")\n";
		}
		// clear error flags and discard bad input
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}




// (QUESTION 2) Function to change an element at an index and display the old and new values
int modify_value(ofstream& OutFile) {

	int oldIndex = 0;
	int oldValue = 0;
	int newIndex = 0;
	int newValue;

	do {
		try {
			cout << "\nPlease enter an index to change its element: ";
			OutFile << "\nPlease enter an index to change its element: ";
			cin >> oldIndex;
			OutFile << oldIndex << endl;

			if (oldIndex < 0 || oldIndex >= SIZE - 1) {
				cout << "\nInvalid index [" << oldIndex << "]. Please enter a valid index from 0 to 99.\n";
				OutFile << "\nInvalid index [" << oldIndex << "]. Please enter a valid index from 0 to 99.\n";
				throw out_of_range("Out of range");
			}

		}
		// executed when exception is of type out_of_range
		catch (out_of_range e) {
			cout << "Caught exception: " << e.what() << endl;
			OutFile << "Caught exception: " << e.what() << endl;

		}


	} while (!(oldIndex >= 0 && oldIndex < SIZE-1)); // Ensure valid index input
		if ((oldIndex >= 0 && oldIndex < SIZE-1))
			cout << "\nValid index [" << oldIndex << "]\n\n";
		OutFile << "\nValid index [" << oldIndex << "]\n\n";



	cout << "To what INTEGER would you like to change the element to? ";
	OutFile << "To what INTEGER would you like to change the element to? ";

	cin >> newValue;
	OutFile << newValue << endl;
	oldValue = arr[oldIndex];

	arr[oldIndex] = newValue; // Change the value at the specified index

	cout << "\nBEFORE\n Index = " << oldIndex << "\n Element = " << oldValue << endl;
	OutFile << "\nBEFORE\n Index = " << oldIndex << "\n Element = " << oldValue << endl;

	cout << "\nAFTER\n Index = " << oldIndex << "\n Element = " << newValue << endl;
	OutFile << "\nAFTER\n Index = " << oldIndex << "\n Element = " << newValue << endl;


	return newValue;
}



// Function to display the array elements
void displayArr(int arr[], ofstream& OutFile) { // https://www.tutorialspoint.com/cplusplus-program-to-append-an-element-into-an-array
	
	int elementsPerRow = 10; // Number of elements per row

	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << ", ";
		OutFile << arr[i] << ", ";

		// Print a newline after every 'elementsPerRow' elements
		if ((i + 1) % elementsPerRow == 0) { // https://stackoverflow.com/questions/21009569/how-to-print-specific-amount-of-elements-of-array-per-line
			cout << endl;
			OutFile << endl;

		}

	}
	OutFile << endl;

}

// (QUESTION 3) Function to insert an element at the end of the array
void insertAtEnd(int arr[], int e, ofstream& OutFile) { // https://www.tutorialspoint.com/cplusplus-program-to-append-an-element-into-an-array
	



	try {

		if (cin.fail()) {
			cin.clear();  // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
			cout << "Invalid element. Please enter an integer\n";
		}
		else if (e < 0) {
			cout << "\nInvalid element. Please enter a positive integer over 0.\n";
			OutFile << "\nInvalid element. Please enter a positive integer over 0.\n";

			throw out_of_range("Out of range");
			std::cin.clear(); // Clear the error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
		}
		else if (e == 0) {
			cout << "\nInvalid element. Please enter an integer greater than 0.\n";
			OutFile << "\nInvalid element. Please enter an integer greater than 0.\n";

			throw out_of_range("Out of range");
			std::cin.clear(); // Clear the error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
		}
		
	}
	// executed when exception is of type out_of_range
	catch (out_of_range e) {
		cout << "Caught exception: " << e.what() << endl;
		OutFile << "Caught exception: " << e.what() << endl;

	}


	int n = num_of_elements();
 if (n < SIZE && arr[n] == NULL) {
		arr[n] = e;
	}
	n = n + 1;

}



void removeElement(int arr[], int key, ofstream& OutFile) { // https://stackoverflow.com/questions/879603/remove-an-array-element-and-shift-the-remaining-ones
	cout << "\nPlease enter an index to remove its element:  ";
	OutFile << "\nPlease enter an index to remove its element:  ";

	cin >> key;
	OutFile << key << endl;

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
		OutFile << arr[i] << " ";

	// decrement the number of items by one
	// num_items -= num_items;

}