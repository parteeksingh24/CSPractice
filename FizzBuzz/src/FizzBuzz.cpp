//============================================================================
// Name        		: FizzBuzz.cpp
// Author			: Parteek Singh
// Course			: CS Review
// Last Modified   	: 04/16/2021
// Description 		: Implementing a few "FizzBuzz" type questions in C++!
//						FizzBuzz is a popular programming exercise, where
//						we print out all numbers from 1 to 100, but when we
//						reach a multiple of 3, we print "Fizz" and when we
//						see a multiple of 5, we print "Buzz". For numbers
//						that are multiples of both 3 and 5, print "FizzBuzz".
//						This exercise, plus a few other variations, are
//						implemented below.
//============================================================================

#include <iostream>
using namespace std;

int main() {//main

	for(int i = 1; i <= 30; i++) {//for
		if(i % 3 == 0) {//if
			cout << "Fizz";
		}//if
		if(i % 5 == 0) {//if
			cout << "Buzz";
		}//if
		if(i % 3 != 0 && i % 5 != 0) {//if
			cout << i;
		}//if

		cout << endl;
	}//for

	cout << endl;
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main
