//============================================================================
// Name        		: FindingMedian.cpp
// Author			: Parteek Singh
// Course			: CS Review
// Last Modified   	: 04/19/2021
// Description 		: For a given string, this function will swap all
//						instances of a character with another, and vice versa.
//============================================================================

#include <iostream>
using namespace std;

string doubleSwap(string, char, char);	//Function prototype

int main() {//main

	cout <<	doubleSwap("aabbccc", 'a', 'b')		<< endl;	//bbaaccc
	cout << doubleSwap("dzefadbbaf", 'a', 'f')	<< endl;	//dzeafdbbfa

	cout << doubleSwap("1244526", '2', '8')		<< endl;	//1844586
	cout << doubleSwap("12345678", '0', '9') 	<< endl;	//12345678

	cout << endl;
	cout << "Program ending, have a nice day!" 	<< endl;
	return 0;
}//main

//----------
//Functions:
//----------
string doubleSwap(string inputStr, char c1, char c2) {//doubleSwap
	for(int i = 0; i < inputStr.size(); i++) {//for
		if(inputStr[i] == c1) {//if
			inputStr[i] = c2;
		}//if
		else if(inputStr[i] == c2) {//if
			inputStr[i] = c1;
		}//else if
		else {}
	}//for

	return inputStr;
}//doubleSwap
