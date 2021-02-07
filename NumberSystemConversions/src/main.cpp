//============================================================================
// Name        : NumberSystemConversions.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>						//Needed for input/output using cin, cout
#include <string>						//For working with the C++ string class
#include <cmath>						//Allows use of the pow() function
#include <limits>						//For ignoring all invalid input
using namespace std;					//The standard namespace is used (for cin, cout, etc)

//FUNCTION PROTOTYPES:
	string 	reverse(string);			//Reverses a given string
	int		showDec(char);				//Finds the decimal equivalent of a given hexadecimal character
	bool	checkBinary(string);		//Determines if a given string is a binary #, used by "binaryToDecimal"
	bool	checkHexadecimal(string);	//Determines if a given input is a valid hex number (0-9, a-f)

	string	decimalToBinary(string);	//CONVERTS a decimal # (integer) to a binary # (string)
	int 	binaryToDecimal(string);	//CONVERTS from a binary # to a decimal #
	string	decimalToHex(string);		//CONVERTS a decimal # (int) into a hexadecimal #
	int 	hexToDecimal(string);		//CONVERTS a hex value into a decimal value

int main() {//main
//VARIABLES:
	int 		menuChoice	= 0;		//Holds the user's choice for the main menu (used in switch statement)
	const int 	EXIT_CODE 	= 9;		//Per the instructions, if the number 9 is entered, exit the program
	string 		decimalNum	= "";		//Used for the decimal conversions to binary and hex, respectively
	string		userInput	= "";		//Stores the binary or hex number entered by user

//START OF PROGRAM:
//Display a welcome message, along with information about program:
	cout << "\tWelcome to the Numeric Converter!" 					<< endl;
	cout << "===================================================" 	<< endl;
	cout << "Select a menu option from below to convert between\n";
	cout << "the decimal, binary, and hexadecimal number systems."	<< endl;

//Main while loop used to get user input, display menu:
	while(menuChoice != EXIT_CODE) {//while (the user's choice is NOT the exit code determined above)
	//Print the main menu, which repeats until while loop is exited (when user enters 9)
		cout << endl 	<< "\tConversion Main Menu\n"
						<< "\t--------------------\n"
						<< "\t1) Decimal to Binary\n"
						<< "\t2) Binary to Decimal\n"
						<< "\t3) Decimal to Hex\n"
						<< "\t4) Hex to Decimal\n"
						<< "\t9) Exit Program\n\n"
						<< "Enter your choice: ";
		/*
			 NOTE:	The "\t" is a horizontal tab, used for formatting.
					The "\n" will move to the next line, like using "endl", also used for formatting
		 */

	//Read in the user's choice:
		cin >> menuChoice;
		cin.ignore();
		/*
			 NOTE: the ignore function tells the cin object to skip one or more characters
				   when reading input from the keyboard. Without parameters, this will
				   skip the newline character(\n) before reading any input later on,
				   which allows a user to press ENTER and not have it affect the reading
				   of data later on in the program.
		 */

	//To prevent the user from typing in a string of letters for the menu choice
		while(cin.fail() == true) {//while
			//cout << "ERROR: Please enter a valid menu option." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}//while

		/*
		 	 NOTE: the clear and ignore functions

		 	 TODO add notes here!
		 */

		//Determine which function to run based on given input, using a switch statement
		switch(menuChoice) {//switch
		case 1:
			//Call decimalToBinary function
			try {//try
				cout << "Enter a non-negative decimal number up to 8 digits long: ";
				getline(cin, decimalNum);

				string binaryValue = decimalToBinary(decimalNum);
				cout << "The number " 	<< decimalNum 	<< " in binary is: "
										<< binaryValue	<< endl;
			}//try
			catch(invalid_argument &error1) {//catch
				cout << "Error: Please enter a decimal value!\n"
						"\tReturning to main menu." << endl;
			}//catch
			catch(out_of_range &error2) {//catch
				cout << "Error: Please enter a decimal value\n"
						"\tup to 8 digits long." << endl;
			}//catch
			catch(string &badInput) {//catch
				cout << badInput << endl;
			}//catch

			break;
		case 2:
			//Call binaryToDecimal function
			try {//try
				cout << "Enter a binary number up to 8 bits long: ";
				getline(cin, userInput);

				int decValue = binaryToDecimal(userInput);
				cout << "The number "	<< userInput 	<< " in decimal is: "
										<< decValue		<< endl;
			}//try
			catch(string &badInput) {//catch
				cout << badInput << endl;
			}//catch

			break;
		case 3:
			//Call decimalToHex function
			try {//try
				cout << "Enter a non-negative decimal number up to 8 digits long: ";
				getline(cin, decimalNum);

				string hexValue = decimalToHex(decimalNum);
				cout << "The number " 	<< decimalNum 	<< " in hexadecimal is: "
										<< hexValue		<< endl;
			}//try
			catch(invalid_argument &error1) {//catch
				cout << "Error: Please enter a decimal value!\n"
						"\tReturning to main menu." << endl;
			}//catch
			catch(out_of_range &error2) {//catch
				cout << "Error: Please enter a decimal value\n"
						"\tup to 8 digits long." << endl;
			}//catch
			catch(string &badInput) {//catch
				cout << badInput << endl;
			}//catch

			break;
		case 4:
			//Call hexToDecimal function
			try {//try
				cout << "Enter a hexadecimal number, up to 4 digits long: ";
				getline(cin, userInput);

				int decimalVal = hexToDecimal(userInput);
				cout << "The number " 	<< userInput 	<< " in decimal is: "
										<< decimalVal 	<< endl;
			}//try
			catch(string &badInput) {//catch
				cout << badInput << endl;
			}//catch

			break;
		case EXIT_CODE:
			//Exit the program
			cout << endl << "Program ending, have a nice day!";
			break;
		default:
			//If none of the options are chosen, an error message will display
			cout << "Error: Please select an option from the menu below. \n"
			<< "\tThe valid choices are the numbers 1, 2, 3, 4, and 9." 			<< endl;

		}//switch
	}//while

	return 0;	//Return value for the main function, to indicate everything ran correctly!
}//end of main function

//FUNCTIONS:
//----------------------------------------------------------------
string reverse(string input) {//reverseAGivenString
	string returnStr = "";			//This is where we store the reversed string

	for(int i = input.size() - 1; i >= 0; i--) {//for (prints from end of string to beginning)
		returnStr += input[i];		/*
									   Adds each character of original string to reversed string.
										Since we're looping "backwards", this will start from the
										end of the original string, and keep adding the current
										character to a new string, until we reach the front of
										the original string.
									*/
	}//for

	return returnStr;				//Return the reversed string
}//reverseAGivenString

int	showDec(char hexValue) {//showDecimalValue
	int returnVal = 0;

	if(hexValue >= '0' && hexValue <= '9') {//if
		returnVal = hexValue - 48;
	}//if
	else {//else
		returnVal = hexValue - 87;
	}//else

	return returnVal;
}//showDecimalValue

bool checkBinary(string binaryNum) {//checkIfBinary
	bool isBinary = true;

	for(int i = 0; i < binaryNum.size(); i++) {//for
		if(binaryNum[i] != '0' && binaryNum[i] != '1') {//if
			isBinary = false;
		}//if
	}//for

	return isBinary;
}//checkIfBinary

bool checkHexadecimal(string hexNum) {//checkIfHex
	bool result = true;

	for(unsigned int i = 0; i < hexNum.size(); i++) {//for
		if(showDec(hexNum[i]) < 0 || showDec(hexNum[i]) > 15) {//if
			result = false;
			break;
		}//if
		else {//else
			continue;
		}//else
	}//for

	return result;
}//checkIfHex

string	decimalToBinary(string str) {//decToBinary
	string 	binaryNum 	= "";			//The converted number (in binary form)
	int 	decNum		= stoi(str);	//The integer version of the given input
	string 	badInput	= "";			//To hold the error if the number entered is invalid

	if(decNum < 0) {//if
		badInput = "Error: Please enter a non-negative (0 and above) value only.";
		throw badInput;
	}//if
	else if(str.length() > 8) {//else if
		badInput = "Error: The maximum length is 8 digits, please try again.";
		throw badInput;
	}//else if
	else {//else
		int remainder = 0;			//Since we are dividing by 2, this will be either 0 or 1

		do {//do
			remainder = decNum % 2;	//Stores the remainder when dividing "decNum" by 2
			binaryNum += to_string(remainder);
			decNum = decNum / 2;	//Will truncate any decimal/"floating point" part
		}//do
		while(decNum != 0);
	}//else

	return reverse(binaryNum);
}//decToBinary

int	binaryToDecimal(string inputStr) {//binaryToDecimal
	string 	binaryNum 	= "";		//Will hold the binary input, granted it is a valid binary string
	int 	decimalNum	= 0;		//The converted number in decimal form to be returned
	string	badInput	= "";		//Holds any exception thrown, if binary string given is invalid

	if(checkBinary(inputStr) == false) {//if
		badInput		= "Error: Please enter a binary number (only include 1s and 0s).";
		throw badInput;
	}//if
	else if(inputStr.length() > 8) {//else if
		badInput		= "Error: The maximum length is 8 digits, please try again.";
		throw badInput;
	}//else if
	else {//else
		binaryNum		= reverse(inputStr);	//Start from least significant bit (LSB)
		int temp		= 0;					//Will hold the numerical value of the characters in string, based on ASCII table

		for(int i = 0; i < binaryNum.size(); i++) {//for
			temp = binaryNum[i] - '0';
				/*
				 Converts the ASCII value of the char to its numerical value.
				 To convert the ASCII value to an integer value, we can subtract the value of the zero character, '0'.
				 Recall that the ASCII character '0' is 48 in decimal, and a digit like '9' is 57, so when we subtract
					by the '0', we are essentially subtracting the difference in decimal form

				 Basically, it figures out the distance from '0'!
				 */

			decimalNum 	+= ( (pow(2, i)) * temp );	//Multiply by the corresponding power of 2
		}//for
	}//else

	return decimalNum;
}//binaryToDecimal

string	decimalToHex(string str) {//toHexadecimal
	string 	hexNum		= "";
	int 	decNum		= stoi(str);
	int		remainder	= 0;
	string 	badInput	= "";			//To hold the error if the number entered is negative, or longer than 8 digits

	if(decNum < 0) {//if
		badInput = "Error: Please enter a non-negative (0 and above) value only.";
		throw badInput;
	}//if
	else if(str.length() > 8) {//else if
		badInput = "Error: The maximum length is 8 digits, please try again.";
		throw badInput;
	}//else if
	else {//else
		while(decNum != 0) {//while
			remainder 	= decNum % 16;

			if(remainder < 10) {//if
				//To get values between 48 and 57 in ASCII table (the values 0-9)
				hexNum.push_back(remainder + 48);
			}//if
			else {//else
				//To get the values of lower case letters in ASCII table, since remainder will be 10 and above
				hexNum.push_back(remainder + 87);
			}//else

			decNum 		= decNum / 16;
		}//while
	}//else

	return reverse(hexNum);
}//toHexadecimal

int	hexToDecimal(string hexValue) {//hexToDecimal
	string 	reverseValue 	= "";
	int 	decimalNum		= 0; 	//Holds the running total for the decimal value
	string	badInput		= "";

	if(checkHexadecimal(hexValue) == false) {//if
		badInput = "Error: Please enter a hexadecimal number. \n"
						"\tThe options are the numbers 0-9, and the letters a-f.";
		throw badInput;
	}//if
	else if(hexValue.length() > 4) {//else if
		badInput = "Error: The maximum length for the number is 4 digits.\n"
						"\tPlease try again.";
		throw badInput;
	}//else if
	else {//else
		reverseValue = reverse(hexValue); //Allows our for loop to increment up, starting from least significant digit
		int temp = 0;	//Stores the converted hex values as their decimal equivalents

		for(int i 	= 0; i < reverseValue.size(); i++) {//for
			if( reverseValue[i] >= '0' && reverseValue[i] <= '9') {//if
				temp	= reverseValue[i] - 48;
			}//if
			else if(reverseValue[i] >= 'a' && reverseValue[i] <= 'f') {//else if
				temp	= reverseValue[i] - 87;
			}//else if
			else {}

			decimalNum	= decimalNum + ( (pow(16, i)) * temp );
		}//for
	}//else

	return decimalNum;
}//hexToDecimal
