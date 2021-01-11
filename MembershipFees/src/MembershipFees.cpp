//============================================================================
// Name        : MembershipFees.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>	//setprecision
using namespace std;

int main() {//main

//Membership fee starts at $2,500 and increases by 4% each year for 6 years
	const float INCREASE 	=	0.04;
	const int 	YEARS		= 	6;
	float		memberFee 	= 	2500;

/*	Solved using a for loop:
		for(int i = 0; i < YEARS; i++) {//for
			memberFee += (memberFee * INCREASE);
			cout << "Current membership fee is: " << memberFee 					<< endl;
		}//for
*/

//Solved using a while loop:
	unsigned int yearsElapsed = 0;

	while(yearsElapsed < YEARS) {//while
		memberFee = memberFee + (memberFee * INCREASE);
		cout << "Current fee is: $" << setprecision(2) << fixed << memberFee	<< endl;
		yearsElapsed++;
	}//while

	cout << endl;
	cout << "Program ending, have a nice day!" 									<< endl;
	return 0;
}//main
