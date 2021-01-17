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
int* expand(int[], int);
int* shift(int[], int);

int main() {//main
//Variables used:
	const int SIZE = 5;
	int* arrPtr = nullptr;

//Create array of integers with initialized values and print this array:
	int numbers[SIZE] = {5, 10, 25, 100, 2};
	cout << "Here is the original array: " << endl;
	for(int i = 0; i < SIZE; i++) {//for
		cout << "\t" << numbers[i] << " ";
	}//for

//Call the reverse functions with this array and print:
	cout << endl << endl;
	cout << "Now in reverse: " << endl;
	arrPtr = reverse(numbers, SIZE);
	for(int i = 0; i < SIZE; i++) {//for
		cout << "\t" << *(arrPtr + i) << " ";
		//cout << arrPtr[i] << endl;
	}//for

//Expand the array and print:
	cout << endl << endl;
	cout << "Doubling the array: " << endl;
	arrPtr = expand(arrPtr, SIZE);
	for(int i = 0; i < (2 * SIZE); i++) {//for
		cout << "\t" << *(arrPtr + i) << " ";
	}//for

//Shift the array and print:
	cout << endl << endl;
	cout << "Now after we shift the array: " << endl;
	arrPtr = shift(arrPtr, SIZE);
	for(int i = 0; i < (2*SIZE + 1); i++) {//for
		cout << "\t" << *(arrPtr + i) << " ";
	}//for

//Free up dynamically allocated memory:
	delete arrPtr;

//End the program:
	cout << endl << endl;
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

int* expand(int arr[], int size) {//expandArray
	int newSize = 2 * size;
	int* copy = new int[newSize];

	for(int i = 0; i < size; i++) {//for
		if(i < size) {//if (we are still within original array size)
			copy[i] = arr[i];
		}//if
		else {//else
			copy[i] = 0;	//All other values (beyond original array) are set to 0
		}//else
	}//for

	return copy;
}//expandArray

int* shift(int arr[], int size) {//shiftArray
	int newSize = size + 1;
	int* shiftPtr = new int[newSize];
	shiftPtr[0] = 0;		//Initialize first element of new array to 0, based on instructions

	for(int i = 1; i <= newSize; i++) {//for
		shiftPtr[i] = arr[i - 1];
	}//for

	return shiftPtr;
}//shiftArray
