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

//Find number of floors in hotel:
	cout << "Please enter the number of floors: ";
	cin >> floors;
	cout << endl;

//Get input for the # of rooms (and occupied rooms) for each floor from 1 to total # of floors
	for(int i = 1; i <= floors; i++) {//for
		cout << "How many rooms are on floor " << i << "?: ";
		cin >> rooms;

		cout << "How many rooms are occupied?: ";
		cin >> occupied;

		cout << endl;

	//Calculate total rooms in hotel, and total occupied from user input for each floor:
		totalRooms 		= totalRooms + rooms;
		totalOccupied 	= totalOccupied + occupied;
	}//for

//Calculate the occupancy rate for hotel:
	cout << endl;
	percentOccupied = ( (static_cast<double>(totalOccupied))  / totalRooms) * 100;
	cout << "Hotel occupancy is " << setprecision(2) << fixed << percentOccupied << "%" << endl;

	cout << "Program ending, have a nice day!";
	return 0;
}//main
