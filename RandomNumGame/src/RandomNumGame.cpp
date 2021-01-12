//============================================================================
// Name        : RandomNumGame.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>		//For srand() and rand()
#include <ctime>		//For time()
using namespace std;

int main() {//main
//Variables:
	int userGuess 		= 0;
	int randomNum		= 0;
	int counter			= 0;
	const int MIN_NUM 	= 1;
	const int MAX_NUM	= 100;

//Welcome message:
cout << "--------------------------------------------" 	<< endl;
cout << "Welcome to the Random Number game"				<< endl;
cout << "Try to guess which number I'm thinking of!"	<< endl;
cout << "============================================" 	<< endl;
cout << endl;

//Seed the rand() function (set the starting value):
	srand(time(0));	/* Uses the current time to initalize the seed.
						This ensures we get different numbers each time the program runs.
						time(0) returns the integer # of seconds from a computer's system clock.

					*/

//Generate a random number from 1 to 100:
	randomNum = MIN_NUM + (rand() % MAX_NUM);

//Main loop:
	while(userGuess != randomNum) {//while
		cout << "Guess the number (1 - 100): ";
		cin >> userGuess;

		if(userGuess > randomNum) {//if
			cout << "Too high, try again!" 	<< endl;
		}//if
		else if(userGuess < randomNum) {//else if
			cout << "Too low, try again!"	<< endl;
		}//else if

		counter++;
	}//while

/* If while loop ends, the user has guessed the correct number!
  Display message and end program:
 */
	cout << endl;
	cout << "CONGRATS! You guessed correctly after " << counter << " attempts." << endl;
	cout << endl;
	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//end of main
