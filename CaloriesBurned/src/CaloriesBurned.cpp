//============================================================================
// Name        : CaloriesBurned.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>		//cout, cin, etc
using namespace std;	//cout, endl

int main() {//main

	const float CALORIES = 3.6;	//On this specific treadmill, you burn 3.6 calories per minute of running
	int min				 = 5;	//Starting at minute 5, calculate the calories burned

	while(min <= 30) {//while
		cout << "# of calories burned after " << min << " minutes: " << (CALORIES * min) << endl;
		min = min + 5;			//Calculate every 5 minutes, up until 30 minutes
	}//while

	cout << endl;
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main
