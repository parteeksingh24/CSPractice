//============================================================================
// Name        : Patterns.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Function declarations:
void countUp(int);
void countDown(int);
void pyramid(int);

//Start of main:
int main() {//main

//Variables:
	int numRows = 20;

//Determine sign of pattern:
	cout << "Enter the number of rows you would like: ";
	cin >> numRows;

//Call the function to display a pyramid design:
	cout << endl;
	pyramid(numRows);
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

//-----------------------------------------------------
//FUNCTIONS:
void countUp(int rows) {//countUp
	for(int level = 1; level <= rows; level++) {//outer
		for(int line = 1; line <= level; line++) {//inner
			cout << "+ ";
		}//INNER loop

		cout << "\n";

	}//OUTER loop
	cout << endl;
}//countUp

void countDown(int rows) {//countDown
	for(int level = rows; level >= 1; level--) {//outer
		for(int line = 1; line <= level; line++) {//inner
			cout << "+ ";
		}//INNER loop

		cout << "\n";
	}//OUTER loop
	cout << endl;
}//countDown

void pyramid(int rows) {//pyramid
	for(int i = 1; i <= rows; i++) {//outer
		for(int space = 1; space <= rows - i; space++) {//inner (to create spaces)
			cout << "  ";
		}//INNER (space)

		for(int star = 1; star <= (2*i) - 1; star++) {//inner for star symbol
			cout << "* ";
		}//for (star pattern)
		cout << endl;
	}//OUTER
	cout << endl;
}//pyramid
