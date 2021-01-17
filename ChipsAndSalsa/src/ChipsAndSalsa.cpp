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
	cout << "Please enter the amount of jars sold for each salsa below. " 			<< endl;
	for(int i = 0; i < SIZE; i++) {//for
		cout << salsa[i] << ": ";
		cin  >> jars[i];		//Read in the input into the array for sales numbers

		while(jars[i] < 0) {//while
			cout << "ERROR: Please enter a positive number only." 					<< endl;
			cout << salsa[i] << ": ";
			cin  >> jars[i];	//Read in the input into the array for sales numbers
		}//while
	}//for

//Print information:
	cout << endl << "Salsa sales report" << endl;
	cout << 		"==================" << endl;
	cout << "Total sales: " 	 					<< getTotal(jars) 		<< endl << endl;

	for(int i = 0; i < SIZE; i++) {//for
		cout << "# of " << salsa[i] << " sold is " 	<< jars[i] 						<< endl;
	}//for

	cout << endl << salsa[largest(jars)] 	<< " had the most sales, with "
				 << jars[largest(jars)] 	<< " sold" 								<< endl;
	cout << salsa[smallest(jars)] 			<< " sold the fewest jars, only selling "
				 << jars[smallest(jars)] 	<< " jar(s)" 								<< endl;

//End program:
	cout << endl << "Program ending, have a nice day!" 								<< endl;
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
	for(int i = 1; i < 5; i++) {//for
		if(arr[largest] <= arr[i]) {//if
			largest = i;
		}//if
	}//for
	return largest;
}//mostSold

int smallest(int arr[]) {//leastSold
	int smallest = 0;	//index of the element with smallest value
	for(int i = 1; i < 5; i++) {//for
		if(arr[smallest] >= arr[i]) {//if
			smallest = i;
		}//if
	}//for
	return smallest;
}//leastSold

