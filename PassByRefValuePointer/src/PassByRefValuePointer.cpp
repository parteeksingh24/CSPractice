//============================================================================
// Name        : PassByRefValuePointer.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void passByValue(int);
void passByReference(int &);
void passByPointer(int *);

int main() {//main

	int x = 5;
	cout << x << endl;	//Prints 5 on screen

//Passing by value:
	cout 	  << endl;
	passByValue(x);		//Create a copy of x to use in the passByValue function (myInt, separate from x)
	cout << x << endl;	//Will still print 5 since we created a temporary int variable myInt to hold 200

//Passing by reference:
	cout 	  << endl;
	passByReference(x);	//This will pass the actual x variable, NOT  a copy, and keep any changes made
	cout << x << endl;	/* So, the function will update the value of x depending on what the function does.
							Here, this means when the function changes the value of x to 24,
							it will be changed permanently so when we print x again,

							this will print 24!
						*/

//Passing by pointer:
	cout 	   << endl;
	int *intPtr = &x;	//Points to x (Holds the address of the integer variable x)
	cout << x  << endl;	//Prints 24, since we have updated the value of x after passByRef
	cout << *intPtr << endl;
						//Line 40 prints the value held by the variable intPtr points to, which is 24

	passByPointer(intPtr);		//Prints 30, based on code in "passByPointer" function
	cout << x  << endl;			//Since passing by pointer ALSO permanently updates values, this prints 30
	cout << *intPtr << endl;	//Also prints 30 since intPtr points to x, which has the the value 30 now


	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

//-------------------------------------------------------------------------------------------------
//FUNCTIONS:
void passByValue(int myInt) {//byValue
	myInt = 200;
	cout << myInt	<< endl;
}//byValue

void passByReference(int &anInt) {//byReference
	anInt = 24;
	cout << anInt	<< endl;
}//byReference

void passByPointer(int *intPtr) {//byPointer
	*intPtr = 30;	//Dereference the int pointer and give it a value of 30
	cout << *intPtr	<< endl;
}//byPointer

//-------------------------------------------------------------------------------------------------
/* NOTES:


*/
