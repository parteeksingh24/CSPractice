//============================================================================
// Name        : HotelOccupancy.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {//main
//Variables:
	int floors 		= 1;	//Number of floors in hotel
	int rooms 		= 1;	//Number of rooms (for each floor of hotel)
	int occupied	= 0;	//Stores the # of occupied rooms (for each floor)

	cout << "Please enter the number of floors: ";
	cin >> floors;

	for(int i = 1; i <= floors; i++) {//for
		cout << "How many rooms are on floor " << i << "?: ";
		cin >> rooms;

		cout << "How many rooms are occupied?: ";
		cin >> occupied;
	}//for


	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main
