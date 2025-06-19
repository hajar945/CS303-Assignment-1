#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // For any_of
#include <limits>
#include <iterator>


using namespace std;

// Function to display the menu 
void displayMenu();

// Function to calculate and display the result 
void menu1(ofstream& OutFile);

// Function to read data from a file into an array
void readData(ofstream& OutFile);

// Function to find the number of elements in the array
int num_of_elements();

// Function to check if an integer exists in the array
bool IntExists(ofstream& OutFile);

// Function to change an element at an index and display the old and new values
int modify_value(ofstream& OutFile);

// Function to display the array elements
void displayArr(int arr[], ofstream& OutFile);

// Function to insert an element at the end of the array
void insertAtEnd(int arr[], int e, ofstream& OutFile);

// Function to remove an element from the array
void removeElement(int arr[], int key, ofstream& OutFile);

