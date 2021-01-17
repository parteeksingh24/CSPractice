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

	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

//FUNCTIONS:
//-----------------------------------------------------
int* reverse(int arr[], int size) {//reverseArray
	int* arrayCopy = new int[size];
	int counter = 0;

	for(int i = (size - 1); i >= 0; i--) {//for
		while(counter <= size) {//while
			arrayCopy[i] = arr[counter];
			counter++;
		}//while
	}//for
}//reverseArray
