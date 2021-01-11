//============================================================================
// Name        : SumOfNumbers.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {//main
//Variables used:
	int num = 0;	//User input
	int sum = 0;	//Running total for

//Display prompt
	cout 	<< "Please enter a positive integer: ";
	cin		>> num;

//Input Validation: Check if number given by user is a positive integer
	while(num <= 0) {//while
		cout 	<< "ERROR! Please enter a positive integer: ";
		cin		>> num;
	}//while
	cout		<< endl;

//Calculate sum (Alternate method is to use sum = (num * (num + 1)) / 2, rather than a loop!
	for(int i = 0; i <= num; i++) {//for
		sum = sum + i;
	}//for

//Display sum and exit program
	cout << "The sum from 1 to " << num << " is: " << sum 	<< endl;
	cout << "Program ending, have a nice day!" 				<< endl;
	return 0;
}//main
