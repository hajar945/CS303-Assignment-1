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
	

	readData();
	
	minValue();
	minIndex();
	maxValue();
	// maxIndex();
	IntExists();

	modify_value();
	int n = 100;

	cout << "\n\nARRAY BEFORE INSERTION \n";
	displayArr(arr, n);


	cout << "\nPlease enter an element to insert at the end of the array:  ";
	int e = 0;
	cin >> e;
	insertAtEnd(arr, n, e);
	

	cout << "\n\nARRAY AFTER INSERTION \n";

	displayArr(arr, n);

	removeElement(arr, 0);
	

	
	return 0;
}

