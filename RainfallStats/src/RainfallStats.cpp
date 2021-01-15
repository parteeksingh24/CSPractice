//============================================================================
// Name        : RainfallStats.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

/* Prompt:
 	Write a program that lets the user enter the total rainfall for each of 12 months
 	 into an array of doubles. The program should calculate and display the total rainfall
 	 for the year, the average monthly rainfall, & the months with the highest & lowest amounts.

 	Input Validation: Do not accept negative numbers for monthly rainfall figures.
 */

#include <iostream>
using namespace std;

int main() {//main
//Variables:
	double 	rainfallData[12];		//Creates an array of 12 doubles to hold rainfall statistics
	double 	totalRainfall = 0;
	double 	averageRainfall = 0;
	int 	highest;				//Month with highest value
	int 	lowest;					//Month (1-12) with lowest rainfall numbers

//Determine and display monthly rainfall amounts:
	for(int i = 1; i <= 12; i++) {//for
		cout << "Total rainfall (in mm) for month " << i << ": ";
		cin  >> rainfallData[i];
	}//for
	cout << endl;
	cout << "Here are the monthly rainfall stats" << endl;
	cout << "===================================" << endl;
	for(int i = 1; i <= 12; i++) {//for
		cout << "Month " << i << ": " << rainfallData[i] << endl;
	}//for

//Find total rainfall:
	for(int i = 1; i <= 12; i++) {//for
		totalRainfall += rainfallData[i];
	}//for

//Calculate average rainfall, and print both total and average amounts:
	averageRainfall = totalRainfall	 /	12;
	cout << "Total rainfall for the year is " << totalRainfall << endl;
	cout << "On average, there was " << averageRainfall << " mm of rainfall per month" << endl;

//Find the highest and lowest numbers:
	highest = 0;
	for(int i = 1; i <= 12; i++) {//for
		if(rainfallData[i] > rainfallData[highest]) {//if
			highest = i;
		}//if
	}//for
	lowest = 0;
	for(int i = 1; i <= 12; i++) {//for
		if(rainfallData[i] < rainfallData[lowest]) {//if
			lowest = i;
		}//if
	}//for

	cout << "The most rain came in month "  << highest 		<< endl;
	cout << "The least rain came in month " << (lowest + 1) << endl;

	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main
