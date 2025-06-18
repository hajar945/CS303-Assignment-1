// CS303 Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Comp-Sci 303 2025

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of
#include <limits>
#include <iterator>

#include "Functions.h"

using namespace std;


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

		// Ensure valid input
		if (cin.fail()) {
			cin.clear();  // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
			cout << "Invalid input. Please enter a number between 1 and 6.\n";
			continue;  // Restart the loop
		}
		// Display the result 
		switch (choice) {
		case 'A': {
			cout << "You have selected (A) Check if a certain integer exists in the array\n";
			IntExists(OutFile);
			break;
		}
		case 'B': {
			cout << "You have selected (B) Modify a value\n";
			modify_value(OutFile);
			int n = SIZE;
			displayArr(arr, OutFile);

			break;
		}
		case 'C': {
			cout << "You have selected (C) Add an element at the end of the array\n";
			cout << num_of_elements;
			int e = 0;
			cin >> e;

			insertAtEnd(arr, e, OutFile);
			displayArr(arr, OutFile);


			cout << "You have tried adding the elmement " << e << " at the end of the array.\n";

			break;
		}
		case 'D': {
			cout << "You have selected (D) Remove an element from the array\n";
			removeElement(arr, 0, OutFile);
			break;
		}
		case 'E': {
			cout << "You have selected (E) Display the array\n ";
			displayArr(arr, OutFile);
			break;
		}
		case 'F': {
			cout << "You have selected (F) Exit the program\n ";
			return;  // Exit the loop and terminate the program

		}
		default:
			cout << "Invalid choice. Please select a valid option (A, B, C, D).\n";
			break;
		}
	}
}





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

	num_of_elements();
	// Display the menu 
	menu1(OutFile);
	


	/*
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
	*/
	OutFile << " \n\n=========== Output file Close  ===========\n";

	// Close the output file
	OutFile.close();
	return 0;
	
}

