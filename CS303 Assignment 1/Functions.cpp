
#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of
#include <limits>
#include <iterator>

#include "Functions.h"

using namespace std;


const int SIZE = 200; // 200 for plenty of extra space
int arr[SIZE];

// Function to display the menu 
void displayMenu()
{
	cout << " \n\n=================== Menu ====================\n";
	cout << "(A) Check if a certain integer exists in the array\n";
	cout << "(B) Modify a value\n";
	cout << "(C) Add an element at the end of the array\n";
	cout << "(D) Remove an element from the array\n";
	cout << "(E) Display the array\n";
	cout << "(F) Exit the program\n";
	cout << "\nPlease select an option:  \n";

}

// Function to calculate and display the result 
void menu1(ofstream& OutFile)
{
	char choice;

	while (true) {

		displayMenu();
		// Enter the choice 
		cin >> choice;
		choice = (char)toupper(choice);

		// Display the result 
		switch (choice) {
		case 'A': {
			cout << "\nYou have selected (A) Check if a certain integer exists in the array\n";
			OutFile << "\nYou have selected (A) Check if a certain integer exists in the array\n";

			IntExists(OutFile);
			break;
		}
		case 'B': {
			cout << "\nYou have selected (B) Modify a value\n";
			OutFile << "\nYou have selected (B) Modify a value\n";

			modify_value(OutFile);
			int n = SIZE;

			break;
		}
		case 'C': {
			cout << "\nYou have selected (C) Add an element at the end of the array\n";
			OutFile << "\nYou have selected (C) Add an element at the end of the array\n";

			int e = 0;
			cout << "Please enter an element to insert at the end of the array:  ";
			OutFile << "Please enter an element to insert at the end of the array:  ";


			insertAtEnd(arr, e, OutFile);

			break;
		}
		case 'D': {
			cout << "\nYou have selected (D) Remove an element from the array\n";
			OutFile << "\nYou have selected (D) Remove an element from the array\n";

			removeElement(arr, 0, OutFile);
			break;
		}
		case 'E': {
			cout << "\nYou have selected (E) Display the array\n ";
			OutFile << "\nYou have selected (E) Display the array\n ";
			displayArr(arr, OutFile);
			break;
		}
		case 'F': {
			cout << "\nYou have selected (F) Exit the program\n ";
			OutFile << "\nYou have selected (F) Exit the program\n ";

			return;  // Exit the loop and terminate the program

		}
		default:
			cout << "\nInvalid choice. Please select a valid option (A, B, C, D, F).\n";
			OutFile << "\nInvalid choice. Please select a valid option (A, B, C, D, F).\n";

			break;
		}
	}
}






// Function to read data from a file into an array
void readData(ofstream& OutFile) { // https://stackoverflow.com/questions/47426692/read-data-from-a-file-into-an-array-c
	string inFileName = "A1input.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < SIZE; i++)
		{
			inFile >> arr[i];
			// cout << "Element at index '" << i << "' is " << arr[i] << ".\n";
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

	return num_items;
}


bool IntExists(ofstream& OutFile) {

	int index = 0;
	int val = 0;
	val = arr[index];


	do {
		try { // https://www.geeksforgeeks.org/exception-handling-c/
			cout << "Please enter an index to view its element:  ";
			OutFile << "Please enter an index to view its element:  ";


			if (!(cin >> index)) {
				// Non-integer input
				throw invalid_argument("Input is not a valid integer.");
			}

			if (index < 0 || index >= SIZE) {
				cout << "\n\nInvalid index [" << index << "]. Please enter a valid index between 0 and "
					<< SIZE - 1 << ".\n";
				OutFile << "\n\nInvalid index [" << index << "]. Please enter a valid index between 0 and "
					<< SIZE - 1 << ".\n";
				throw out_of_range("Out of range");
			}
			// If we get here, it's valid
			OutFile << index << endl;
			cout << "VALID INDEX [" << index << "] with Element " << arr[index] << endl;
			OutFile << "VALID INDEX [" << index << "] with Element " << arr[index] << endl;
			return true;

		}
		catch (invalid_argument e) {
			cerr << "Invalid input: " << e.what() << "\n";
		}
		// executed when exception is of type out_of_range
		catch (out_of_range e) {
			cout << "Caught exception: " << e.what() << endl;
			OutFile << "Caught exception: " << e.what() << endl;

		}
		// clear error flags and discard bad input
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!(index >= 0 && index < SIZE));

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
			if (!(cin >> oldIndex)) {
				// Non-integer input
				throw invalid_argument("Input is not a valid integer.");
			}

			if (oldIndex < 0 || oldIndex >= SIZE - 1) {
				cout << "\nInvalid index [" << oldIndex << "]. Please enter a valid index from 0 to 99.\n";
				OutFile << "\nInvalid index [" << oldIndex << "]. Please enter a valid index from 0 to 99.\n";
				throw out_of_range("Out of range");
			}
			cout << "\nValid index [" << oldIndex << "]\n\n";
			OutFile << "\nValid index [" << oldIndex << "]\n\n";


			cout << "To what INTEGER would you like to change the element to? ";
			OutFile << "To what INTEGER would you like to change the element to? ";


			if (!(cin >> newValue)) {
				// Non-integer input
				throw invalid_argument("Input is not a valid integer.");
			}
			OutFile << newValue << endl;
			oldValue = arr[oldIndex];

			arr[oldIndex] = newValue; // Change the value at the specified index

			cout << "\nBEFORE\n Index = " << oldIndex << "\n Element = " << oldValue << endl;
			OutFile << "\nBEFORE\n Index = " << oldIndex << "\n Element = " << oldValue << endl;

			cout << "\nAFTER\n Index = " << oldIndex << "\n Element = " << newValue << endl;
			OutFile << "\nAFTER\n Index = " << oldIndex << "\n Element = " << newValue << endl;


			return newValue;

		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Invalid input: " << e.what() << "\n";
			OutFile << "Invalid input: " << e.what() << "\n";

		}
		// executed when exception is of type out_of_range
		catch (out_of_range e) {
			cout << "Caught exception: " << e.what() << endl;
			OutFile << "Caught exception: " << e.what() << endl;

		}
		// clear error flags and discard bad input
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (!(oldIndex >= 0 && oldIndex < SIZE - 1)); // Ensure valid index input

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
		if (!(std::cin >> e)) {
			cin.clear();  // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
			// Non-integer input
			throw std::invalid_argument("Input is not a valid integer.");
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
		int n = num_of_elements();
		if (n < SIZE && arr[n] == NULL) {
			arr[n] = e;
		}
		n = n + 1;
	}
	// executed when exception is of type invalid argument
	catch (invalid_argument e) {
		cout << "Caught exception: " << e.what() << endl;
		OutFile << "Caught exception: " << e.what() << endl;

	}
	// executed when exception is of type out_of_range
	catch (out_of_range e) {
		cout << "Caught exception: " << e.what() << endl;
		OutFile << "Caught exception: " << e.what() << endl;

	}
}



void removeElement(int arr[], int key, ofstream& OutFile) { // https://stackoverflow.com/questions/879603/remove-an-array-element-and-shift-the-remaining-ones
	do {
		try { // https://www.geeksforgeeks.org/exception-handling-c/
			cout << "\nPlease enter an index to remove its element:  ";
			OutFile << "\nPlease enter an index to remove its element:  ";


			if (!(cin >> key)) {
				// Non-integer input
				throw invalid_argument("Input is not a valid integer.");
			}
			if (key < 0 || key >= SIZE) {
				cout << "\n\nInvalid index [" << key << "]. Please enter a valid index between 0 and "
					<< SIZE - 1 << ".\n";
				OutFile << "\n\nInvalid index [" << key << "]. Please enter a valid index between 0 and "
					<< SIZE - 1 << ".\n";
				throw out_of_range("Out of range");
			}
			// If we get here, it's valid
			OutFile << key << endl;
			cout << "VALID INDEX [" << key << "] with Element " << arr[key] << endl;
			OutFile << "VALID INDEX [" << key << "] with Element " << arr[key] << endl;



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


		}
		catch (invalid_argument e) {
			cerr << "Invalid input: " << e.what() << "\n";
		}
		// executed when exception is of type out_of_range
		catch (out_of_range e) {
			cout << "Caught exception: " << e.what() << endl;
			OutFile << "Caught exception: " << e.what() << endl;

		}

	} while (!(key >= 0 && key < SIZE));
}