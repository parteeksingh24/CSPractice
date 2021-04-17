//============================================================================
// Name        		: FindingMedian.cpp
// Author			: Parteek Singh
// Course			: CS Review
// Last Modified   	: 04/16/2021
// Description 		: Finding the median of a vector of integers!
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

float median(std::vector<int> arr);

int main() {//main

//Define the vector of integers:
	vector<int> myArr;

//Adding some values to the vector:
	myArr.push_back(3);
	myArr.push_back(10);
	myArr.push_back(15);
	myArr.push_back(12);
	myArr.push_back(11);
	myArr.push_back(2);
	myArr.push_back(1);
	myArr.push_back(0);

//Now, let's find the median of the data:
	cout << "The median is: " << median(myArr) << endl;

//End the program:
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

float median(std::vector<int> arr) {//findMedian
	float result = 0.0;	//The median value, to be returned

	//First we will sort the vector in ascending order:
	sort(arr.begin(), arr.end());	//By default, in ascending order

	//Next, determine the median:
	if(arr.size() % 2 != 0) {//if	(the number of elements is ODD)
		result = arr[(arr.size() / 2)];
	}//if
	else {//else (the number of elements is EVEN)
		int value1 = arr[ (arr.size() / 2) - 1 ];
		int value2 = arr[arr.size() / 2];

		result = ( double(value1 + value2) / 2 );
			//We include the "double" to avoid integer division, which truncates the decimal!
	}//else

	//Finally, we will return the median:
	return result;
}//findMedian
