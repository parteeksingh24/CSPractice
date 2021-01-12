//============================================================================
// Name        : Patterns.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void countUp(void);

int main() {//main

	countUp();
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

void countUp(void) {//countUp
	for(int level = 1; level <= 10; level++) {//outer
		for(int line = 1; line <= level; line++) {//inner
			cout << "+ ";
		}//INNER loop

		cout << "\n";

	}//OUTER loop
	cout << endl;
}//countUp
