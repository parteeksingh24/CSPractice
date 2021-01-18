//============================================================================
// Name        : ChipsAndSalsa.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int getTotal(int[]);
void largest(string[], int[]);
void smallest(string[], int[]);

int main() {//main
//Variables and definitions:
	const int SIZE = 5;
	string salsa[SIZE] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
	int jars[SIZE];

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
	cout << "Total sales: " 	 					<< getTotal(jars) 			<< endl << endl;

	for(int i = 0; i < SIZE; i++) {//for
		cout << "# of " << salsa[i] << " sold is " 	<< jars[i] 							<< endl;
	}//for

	cout << endl;
	largest(salsa, jars);
	smallest(salsa, jars);

//End program:
	cout << endl << "Program ending, have a nice day!" 									<< endl;
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

void largest(string sales[], int nums[]) {//mostSold
	int largest = 0;			//index of the element with highest value
	vector<int> returnVect;		//vector of all values with highest value

	for(int i = 1; i < 5; i++) {//for
		if(nums[largest] <= nums[i]) {//if
			largest = i;
		}//if
	}//for

	for(int i = 0; i < 5; i++) {//fpr
		if(nums[i] == nums[largest]) {//if
			returnVect.push_back(i);
		}//if
	}//for

	for(int i = 0; i < returnVect.size(); i++) {//for
		if(returnVect.size() == 1) {//if
			if(nums[returnVect.at(0)] == 1) {//if
				cout 	<< sales[returnVect.at(i)] 	<< " had the most sales with "
						<< nums[returnVect.at(0)] 	<< " jar sold"	 					<< endl;
				return;
			}//if
			else {//else
				cout 	<< sales[returnVect.at(i)];
			}//else
		}//if
		else {//else
			cout << sales[returnVect.at(i)] << ", ";
		}//else
	}//for

	cout << "had the most sales with " << nums[returnVect.at(0)] << " jars sold" 	<< endl;
}//mostSold

void smallest(string sales[], int nums[]) {//leastSold
	int smallest = 0;			//index of the element with LOWEST value
	vector<int> returnVect;		//vector of all values with LOWEST value

	for(int i = 1; i < 5; i++) {//for
		if(nums[smallest] >= nums[i]) {//if
			smallest = i;
		}//if
	}//for

	for(int i = 0; i < 5; i++) {//fpr
		if(nums[i] == nums[smallest]) {//if
			returnVect.push_back(i);
		}//if
	}//for

	for(int i = 0; i < returnVect.size(); i++) {//for
		if(returnVect.size() == 1) {//if
			if(nums[returnVect.at(0)] == 1) {//if
				cout 	<< sales[returnVect.at(i)] 	<< " had the least sales with "
						<< nums[returnVect.at(0)] 	<< " jar sold"	 					<< endl;
				return;
			}//if
			else {//else
				cout 	<< sales[returnVect.at(i)];
			}//else
		}//if
		else {//else
			cout 		<< sales[returnVect.at(i)] 	<< ", ";
		}//else
	}//for

	cout << "had the least sales with " << nums[returnVect.at(0)] << " jars sold" 	<< endl;
}//leastSold

