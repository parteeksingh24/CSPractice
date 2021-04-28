//============================================================================
// Name        		: main.cpp
// Author			: Parteek Singh
// Course			: CS Review
// Last Modified   	: 04/27/2021
// Description 		: Adding up the digits of an integer, using modulo and
//						division!
//============================================================================

#include <iostream>
using namespace std;

int digitSum(int num);	//Function prototype

int main() {//main

//Testing out the function:
	cout	<<	digitSum(21250)						<< endl;	//10
	cout	<<	digitSum(0)							<< endl;	//0
	cout	<<	digitSum(555555555)					<< endl;	//45

	cout 	<< 	"Program ending, have a nice day!" 	<< endl;
	return 0;
}//main

//--------------
//Functions:
//--------------
int digitSum(int num) {//digitSum
	int total = 0;				//The running total for sum of all digits of parameter, num

	do {//do
		total 	+= (num % 10);	//Add the remainder after division with base 10, to total
		num		=	num / 10;	//Now that we have added a digit, remove it and continue loop
	}//do
	while(num > 0);

	return total;
}//digitSum
