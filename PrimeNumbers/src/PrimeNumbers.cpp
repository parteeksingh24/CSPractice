//============================================================================
// Name        : PrimeNumbers.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int);
vector<int> findPrimes(int, int);
void print(vector<int> const&);

int main() {//main

	cout << isPrime(5) << endl;		//1, true
	cout << isPrime(4) << endl;		//0, false
	cout << isPrime(22) << endl;	//0
	cout << isPrime(991) << endl;	//1

//Print primes from 1 to 100:
	cout << endl;
	cout << "Here are all the primes from 1 to 100: " << endl;
	print(findPrimes(1, 100));
	cout << endl;

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

vector<int> findPrimes(int start, int end) {//findPrimes (from starting # up to end #)
	vector<int> list;

	for(int i = start; i <= end; i++) {//for
		if(isPrime(i) == true) {//if
			list.push_back(i);
		}//if
	}//for

	return list;
}//displayPrimes

void print(vector<int> const &primes) {//printPrimes
	for(int i = 0; i < primes.size(); i++) {//for
		cout << primes.at(i) << " ";
	}//for
}//printPrimes
