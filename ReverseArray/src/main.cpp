//============================================================================
// Name        : ReverseArray.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int* reverse(int[], int);

int main() {//main
//Variables used:
	const int SIZE = 5;
	int* reverseArr = nullptr;

//Create array of integers with initialized values and print this array:
	int numbers[SIZE] = {5, 10, 25, 100, 2};
	cout << "Here is the original array: " << endl;
	for(int i = 0; i < SIZE; i++) {//for
		cout << "\t" << numbers[i] << " ";
	}//for

//Call the reverse functions with this array and print:
	cout << endl << endl;
	cout << "Now in reverse: " << endl;
	reverseArr = reverse(numbers, SIZE);
	for(int i = 0; i < SIZE; i++) {//for
		cout << "\t" << *(reverseArr + i) << " ";
	}//for

//End the program:
	cout << endl;
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

//FUNCTIONS:
//-----------------------------------------------------
int* reverse(int arr[], int size) {//reverseArray
	int* arrayCopy = new int[size];
	int counter = 0;

	for(int i = (size - 1); i >= 0; i--) {//for
		if(counter <= size) {//if
			arrayCopy[i] = arr[counter];
			counter++;
		}//if
	}//for
	return arrayCopy;
}//reverseArray
