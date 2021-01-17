//============================================================================
// Name        : ChipsAndSalsa.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int getTotal(int[]);
int largest(int[]);
int smallest(int[]);

int main() {//main
//Variables and definitions:
	const int SIZE = 5;
	string salsa[SIZE] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
	int jars[SIZE];
	int amount = 0;	//User input for amount of each salsa type sold

//Find the number of jars sold for each salsa type:
	cout << "Please enter the amount of jars sold for each salsa below. " << endl;
	for(int i = 0; i < SIZE; i++) {//for
		cout << salsa[i] << ": ";
		cin  >> amount;

		while(amount < 0) {//while
			cout << "ERROR: Please enter a positive number only." << endl;
			cout << "# of " << salsa[i] << "sold: ";
			cin  >> amount;
		}//while

		jars[i] = amount;
	}//for

//Print information:
	cout << endl << "Salsa sales report" << endl;
	cout << 		"==================" << endl;
	for(int i = 0; i < SIZE; i++) {//for
		cout << "# of " << salsa[i] << " sold is " 	<< jars[i] 			<< endl;
		cout << "Total sales: " 	 				<< getTotal(jars) 	<< endl;
	}//for

	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

//FUNCTIONS:
//-----------------------------------------------------
int getTotal(int arr[]) {//totalSales
	int total = 0;
	for(int i = 0; i < 5; i++) {//for
		total = total + arr[i];
	}//for
	return total;
}//totalSales

int largest(int arr[]) {//mostSold
	int largest = 0;	//index of the element with highest value

}//mostSold
