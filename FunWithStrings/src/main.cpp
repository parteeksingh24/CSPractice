//============================================================================
// Name        : FunWithStrings.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int length (char []);
void reverse(char*);

int main(void) {//main
	char str[] = "Hello";

	cout << length(str) << endl;
	reverse(str);


	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

/* FUNCTIONS:
 * ====================================================
 */
int length(char word[]) {//stringLength
	int counter = 0;

	while(word[counter] != '\0') {//while
		counter++;
	}//while

	return counter;
}//stringLength

void reverse(char* str) {//reverse
	int position = length(str) - 1;	//Start at the last character of c-string

	while(position >= 0) {//while
		cout << *(str + position) << " ";
		position--;
	}//while
	cout << endl;
}///reverse
