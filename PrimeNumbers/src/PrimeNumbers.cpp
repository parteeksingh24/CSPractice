//============================================================================
// Name        : PrimeNumbers.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool isPrime(int);

int main() {//main

	cout << isPrime(5) << endl;		//1
	cout << isPrime(4) << endl;		//0
	cout << isPrime(22) << endl;	//0
	cout << isPrime(991) << endl;	//1

	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

//-----------------------------------------------------
//Functions:
bool isPrime(int num) {//checkPrime
	int divisorCount = 0;

	for(int i = 1; i <= num; i++) {//for
		if(num % i == 0) {//if
			divisorCount++;
		}//if
	}//for

	if(divisorCount == 2) {//if
		return true;
	}//if
	else {//else
		return false;
	}//else

}//checkPrime
