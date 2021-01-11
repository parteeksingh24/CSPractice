//============================================================================
// Name        : HotelOccupancy.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>	//setprecision
using namespace std;

int main() {//main
//Variables:
	int floors 				= 0;	//Number of floors in hotel
	int rooms 				= 0;	//Number of rooms (for each floor of hotel)
	int occupied			= 0;	//Stores the # of occupied rooms (for each floor)
	int totalRooms			= 0;	//Adds up all rooms from all floors
	int totalOccupied 		= 0;	//How many total rooms are currently occupied
	float percentOccupied 	= 0.0;	//Occupancy rate for hotel (how many rooms are filled)
	const int MIN_FLOORS	= 1;	//Based on assignment, # of floors must be 1 and above
	const int MIN_ROOMS		= 10;	//Each floor must have at least 10 rooms, based on assignment

	const int REMOVED_FLOOR	= 13;	/*	Some hotels don't include a 13th floor, but this can
										be used to also shut down a floor for maintenance, etc.
									*/

//Find number of floors in hotel:
	cout << "Please enter the number of floors: ";
	cin >> floors;
	while(floors < MIN_FLOORS) {//while
		cout << "Error! The number of floors cannot be less than " << MIN_FLOORS << endl;
		cout << "Please enter the number of floors: ";
		cin >> floors;
	}//while
	cout << endl;

//Get input for the # of rooms (and occupied rooms) for each floor (from 1 to total # of floors):
	for(int i = 1; i <= floors; i++) {//for
		if(i == REMOVED_FLOOR) {//if
			continue;
		}//if

		cout << "How many rooms are on floor " << i << "?: ";
		cin >> rooms;

		while(rooms < MIN_ROOMS) {//while
			cout << "Error! The number of rooms cannot be less than " << MIN_ROOMS << endl;
			cout << "How many rooms are on floor " << i << "?: ";
			cin >> rooms;
		}//while

		cout << "How many rooms are occupied?: ";
		cin >> occupied;

		while(occupied > rooms) {//while
			cout << "Error! The number of occupied rooms can't be more than " << rooms << endl;
			cout << "How many rooms are occupied?: ";
			cin >> occupied;
		}//while

		cout << endl;

	//Calculate total rooms in hotel, and total occupied from user input for each floor
		totalRooms 		= totalRooms + rooms;
		totalOccupied 	= totalOccupied + occupied;
	}//FOR loop end

//Calculate the occupancy rate for hotel:
	cout << endl;
	percentOccupied = ( (static_cast<double>(totalOccupied))  / totalRooms) * 100;

//Display all information and end program:
	cout << "Number of rooms is "  << totalRooms << endl;
	cout << "There are currently " << totalOccupied << " occupied rooms" << endl;

	if((totalRooms - totalOccupied) != 0) {//if
		cout << (totalRooms - totalOccupied) << " rooms are available at the moment" << endl;
	}//if
	else {//else
		cout << "Sorry for the inconvenience, no rooms are currently available" << endl;
	}//else

	cout << "Hotel occupancy is " << setprecision(2) << fixed << percentOccupied << "%" << endl;
	cout << endl;
	cout << "Program ending, have a nice day!";
	return 0;
}//main
