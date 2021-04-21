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

//Beginning with the classic FizzBuzz question, with values from 1 to 100:
//	for(int i = 1; i <= 100; i++) {//for
//		if(i % 3 == 0) {//if	(the current number is a multiple of 3)
//			cout << "Fizz";
//		}//if
//		if(i % 5 == 0) {//if	(the number is a multiple of 5)
//			cout << "Buzz";
//		}//if
//		if(i % 3 != 0 && i % 5 != 0) {//if	(the number is not a multiple of 3 or 5)
//			cout << i;		//If not a multiple of 3 or 5, just print the number out
//		}//if
//
//		cout << endl;		//To space out the results
//	}//for

//Now, let's only replace the digits 3, 5 with the words "Fizz" and "Buzz":
	for(int i = 0; i <= 35; i++) {//for
		//First we must convert the number to a string:
		string tempStr = to_string(i);

		//Next, we will go through this number/string and look for a 3/5:
		for(int k = 0; k < tempStr.size(); k++) {//for (inner)
			if(tempStr[k] == '3') {//if
				tempStr.replace(k, 1, "Fizz");
			}//if
			else if(tempStr[k] == '5') {//else if
				tempStr.replace(k, 1, "Buzz");
			}//else if
			else {//else
				continue;
			}//else
		}//for (inner)

		cout << tempStr << endl;
	}//for (outer)

//Ending the program with an exit message, and return code 0 to indicate no errors:
	cout << endl;
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main
