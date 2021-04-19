//============================================================================
// Name        		: main.cpp
// Author			: Parteek Singh
// Course			: CS Review
// Last Modified   	: 04/19/2021
// Description 		: Finding the sum of the first n terms of a vector!
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int sliceSum(vector<int>, int);	//Function prototype

int main() {//main

//Defining an array of integers, for testing:
	vector<int> myArray;

//Adding some values to the vector:
	myArray.push_back(9);
	myArray.push_back(8);
	myArray.push_back(7);
	myArray.push_back(6);
	myArray.push_back(1);

//Let's print the results of the "sliceSum" array with different values of "n":
	cout <<	sliceSum(myArray, 3)				<< endl;	//24
	cout << sliceSum(myArray, -2)				<< endl;	//0
	cout << sliceSum(myArray, 10)				<< endl;	//31

	cout << endl;
	cout << endl;

	cout << sliceSum(myArray, 0)				<< endl;	//0
	cout << sliceSum(myArray, 2)				<< endl;	//17
	cout << sliceSum(myArray, 66)				<< endl;	//31

	cout << endl;
	cout << "Program ending, have a nice day!" 	<< endl;
}//main

//======================================================================
//FUNCTIONS:
//----------------------------------------------------------------------

int sliceSum(std::vector<int> arr, int n) {//sliceSum
	int sum	=	0;		//The sum to return, based on size of input "n"
	if(n <= 0) {//if (the input given is negative, or 0)
		sum = 0;			//In this case, the sum will be 0
	}//if
	else if(n > 0 && n <= arr.size()) {//else if (the size is up to array size)
		for(int i = 0; i <= n - 1; i++) {//for
			sum += arr[i];	//Add up each integer array value to the total sum
		}//for
	}//else if
	else {//else (if n is bigger than the size of array)
		for(int i = 0; i < arr.size(); i++) {//for
			sum += arr[i];	//Add up *all* values in array
		}//for
	}//else

	return sum;		//Return the integer result
}//sliceSum
