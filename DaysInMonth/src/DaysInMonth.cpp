//============================================================================
// Name        : DaysInMonth.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {//main
	unsigned int 	month;
	unsigned int 	year;

	cout 	<< "Enter a month (1-12): " 							<< endl;
	cin		>> month;
	cout 	<< "Enter a year: " 									<< endl;
	cin		>> year;
	cout 	<< endl;

	switch(month) {//switch
		//January
			case 1:
				cout << "31 days" << endl;
				break;
		//February
			case 2:
				if(year % 100 == 0) {//if
					if(year % 400 == 0) {//if
						cout << "29 days" 	<< endl;
					}//inner IF
					else {//else
						cout << "28 days" 	<< endl;
					}//else
				}//outer IF

				else if(year % 4 == 0) {//else if
					cout << "29 days" 		<< endl;
				}//else if

				else {//else
					cout << "28 days" 		<< endl;
				}//else
				break;
		//March
			case 3:
				cout << "31 days" << endl;
				break;
		//April
			case 4:
				cout << "30 days" << endl;
				break;
		//May
			case 5:
				cout << "31 days" << endl;
				break;
		//June
			case 6:
				cout << "30 days" << endl;
				break;
		//July
			case 7:
				cout << "31 days" << endl;
				break;
		//August
			case 8:
				cout << "31 days" << endl;
				break;
		//September
			case 9:
				cout << "30 days" << endl;
				break;
		//October
			case 10:
				cout << "31 days" << endl;
				break;
		//November
			case 11:
				cout << "30 days" << endl;
				break;
		//December
			case 12:
				cout << "31 days" << endl;
				break;
		//DEFAULT Case:
			default:
				cout << "ERROR: Please enter a valid month (1-12)." << endl;
	}//switch


	cout << "Program ending, have a nice day!" 						<< endl;
	return 0;
}//main
