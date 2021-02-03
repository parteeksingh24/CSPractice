//============================================================================
// Name        : NumberSystemConversions.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//FUNCTION PROTOTYPES:
	string 	reverse(string);			//Reverses a given string, used by "decimalToBinary" function
	string	decimalToBinary(int);		//CONVERTS a decimal # (integer) to a binary # (string)
	bool	checkBinary(string);		//Determines if a given string is a binary #, used by "binaryToDecimal"
	int 	binaryToDecimal(string);	//CONVERTS from a binary # to a decimal #

	string	showHex(int);				//Change to hexadecimal naming system (for numbers 10-15)
	string	decimalToHex(int);			//CONVERTS a decimal # (int) into a hexadecimal #

	int		showDec(char);				//Change a value in hex to its' decimal equivalent
	bool	checkHexadecimal(string);	//Determines if a given input is a valid hex number (0-9, a-f)
	int 	hexToDecimal(string);		//CONVERTS a hex value into a decimal value

int main() {//main
//VARIABLES:
	int 		menuChoice	= 0;	//Holds the user's choice in the main switch statement
	const int 	EXIT_CODE 	= 9;	//Per the instructions, if the number 9 is entered, exit the program
	int 		decimalNum	= 0;	//Used for the decimal conversions to binary and hex, respectively
	string		userInput	= "";	//Stores the binary or hex number entered by user

//START OF PROGRAM:
	//Display a welcome message, along with information about program:
		cout << "\tWelcome to the Numeric Converter!" 		<< endl;
		cout << "===================================================" 	<< endl;
		cout << "Select a menu option from below to convert between\n";
		cout << "the decimal, binary, and hexadecimal number systems." 	<< endl;

	//Main while loop to get user input, display menu:
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

			//Read in the user's choice
			cin >> menuChoice;

			//Determine which function to run based on given input, using a switch statement
			switch(menuChoice) {//switch
				case 1: //Call decimalToBinary function
					cout << "Enter a non-negative decimal number: ";
					cin	 >> decimalNum;

					if(decimalNum < 0) {//if (the given number is negative)
						cout << "Error: Please enter a non-negative number (0 and above) only" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}//if
					else {//else (the decimal number is 0 and above)
						cout << "The number "	<< decimalNum 	<< " in binary is: "
								<< decimalToBinary(decimalNum)	<< endl;
					}//else

					break;
				case 2: //Call binaryToDecimal function
					cout << "Enter a binary number up to 8 bits long: ";
					cin >> userInput;

					if(checkBinary(userInput) == false) {//if (the given number is not binary)
						cout << "Error: Please enter a binary number (only include 1s and 0s)." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}//if
					else if(userInput.length() > 8) {//else if (the given # is more than 8 digits long)
						cout << "Error: The maximum length is 8 digits, please try again." 		<< endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}//else if
					else {//else
						cout << "The number "	<< userInput 	<< " in decimal is: "
								<< binaryToDecimal(userInput)	<< endl;
					}//else

					break;
				case 3: //Call decimalToHex function
					cout << "Enter a non-negative decimal number: ";
					cin	 >> decimalNum;

					if(decimalNum < 0) {//if (the given number is negative)
						cout << "Error: Please enter a non-negative number (0 and above) only" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}//if
					else {//else
						cout << "The number " << decimalNum << " in hexadecimal is: "
								<< decimalToHex(decimalNum) << endl;
					}//else

					break;
				case 4: //Call hexToDecimal function
					cout << "Enter a hexadecimal number, up to 4 digits long: ";
					cin  >> userInput;

					if(userInput.length() > 4) {//if
						cout << "Error: The maximum number of digits is 4. Please try again." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}//if
					else if(checkHexadecimal(userInput) == false) {//else if
						cout << "Error: Please enter a valid hex number. The options are 0-9, a-f." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}//else if
					else {//else
						cout << "The number " << userInput << " in decimal is: "
								<< hexToDecimal(userInput) << endl;
					}//else

					break;
				case 9:	//Exit the program
					cout << endl << "Program ending, have a nice day!";
					break;
				default: //If none of the options are chosen, an error message will display
					cout << "Error: Please select an option from the menu below. \n"
						 << "The valid choices are the numbers 1, 2, 3, 4, and 9" << endl;

			}//switch
		}//while

	return 0;
}//end of main function

//FUNCTIONS:
//----------------------------------------------------------------
string	reverse(string input) {//reverseString
	string returnStr = "";			//This is the reversed string
	for(int i = input.size() - 1; i >= 0; i--) {//for	(prints from end of string to beginning)
		returnStr += input[i];		//Adds each character of original input to returning string
	}//for

	return returnStr;	//return the reversed string
}//reverseString

string	decimalToBinary(int decNum) {//toBinary
	//Using repeated division:
		string str 			= "";			//The converted number (in binary form)
		int quotient		= decNum / 2;	//Will truncate any decimal/"floating point" part
		int remainder		= decNum % 2;	//Stores the remainder when dividing "decNum" by 2

		do {//do
			if(remainder == 0) {//if
				str += "0";
			}//if
			else {//else
				str += "1";
			}//else

			remainder 	= quotient % 2;
			quotient 	= quotient / 2;
		}//do
		while(quotient > 0);
//To account for last digit, when quotient is 0:
		if(remainder == 0) {//if
			str += "0";
		}//if
		else {//else
			str += "1";
		}//else

		return reverse(str);	//Since we end with the MSB, flip it to display in order
}//toBinary

bool checkBinary(string binaryNum) {//checkBinary
	bool isBinary = true;

	for(int i = 0; i < binaryNum.size(); i++) {//for
		if(binaryNum[i] != '0' && binaryNum[i] != '1') {//if
			isBinary = false;
		}//if
	}//for

	return isBinary;
}//checkBinary

int	binaryToDecimal(string inputStr) {//toDecimal
	string binaryNum 	= reverse(inputStr);	//Start from least significant bit (LSB)
	int decimalNum		= 0;					//The converted number in decimal form

	for(int i = 0; i < binaryNum.size(); i++) {//for
		int temp = binaryNum[i] - '0';	//Converts the ASCII value of the char to its numerical value
		//To convert the ASCII value to an integer value, we can subtract the value of the zero character, '0'
		//Recall that the ASCII character '0' is 48 in decimal, and a digit like '9' is 57, so when we subtract
		//by the '0', we are essentially subtracting the difference in decimal form, to get 9 in this case

		//(it figures out the distance from '0')
		decimalNum += ( (pow(2, i)) * temp );	//Multiply by the corresponding power of 2
	}//for

	return decimalNum;
}//toDecimal

string	showHex(int decNum) {//showHexForm
	string returnStr = "";

	if(decNum <= 9) {//if
		returnStr = to_string(decNum);
	}//if
	else if(decNum == 10) {//else if
		returnStr = "a";
	}//else if
	else if(decNum == 11) {//else if
		returnStr = "b";
	}//else if
	else if(decNum == 12) {//else if
		returnStr = "c";
	}//else if
	else if(decNum == 13) {//else if
		returnStr = "d";
	}//else if
	else if(decNum == 14) {//else if
		returnStr = "e";
	}//else if
	else {//else
		returnStr = "f";
	}//else

	return returnStr;
}//showHexForm

string	decimalToHex(int decNum) {//toHexadecimal
	string hexNum 	= "";				//To store the hex value that will be returned by function
	int quotient 	= decNum / 16;
	int remainder 	= decNum % 16;
	hexNum			+= showHex(remainder);

	while(quotient != 0) {//while
		remainder	= quotient % 16;
		hexNum		+= showHex(remainder);		//Convert the integer remainder into its hex equivalent
		quotient	= quotient / 16;
	}//while

	return reverse(hexNum);
}//toHexadecimal

int	showDec(char hexValue) {//showDecimalVersion
	int returnVal = 0;

	if(hexValue == 'f') {//if
		returnVal = 15;
	}//if
	else if(hexValue == 'e') {//else if
		returnVal = 14;
	}//else if
	else if(hexValue == 'd') {//else if
		returnVal = 13;
	}//else if
	else if(hexValue == 'c') {//else if
		returnVal = 12;
	}//else if
	else if(hexValue == 'b') {//else if
		returnVal = 11;
	}//else if
	else if(hexValue == 'a') {//else if
		returnVal = 10;
	}//else if
	else {//else
		returnVal = (hexValue - '0');
	}//else

	return returnVal;
}//showDecimalVersion

bool checkHexadecimal(string hexNum) {//checkHex
	bool result = true;

	for(int i = 0; i < hexNum.size(); i++) {//for
		if(showDec(hexNum[i]) < 0 || showDec(hexNum[i]) > 15) {//if
			result = false;
		}//if
	}//for

	return result;
}//checkHex

int	hexToDecimal(string hexValue) {//toDecimal
	string reverseValue = reverse(hexValue);	//Allows our for loop to start from the most significant digit and increment up
	int temp			= 0;	//Stores the converted hex values (10-15) as their decimal equivalents
	int decimalNum 		= 0;	//Holds the running total for the decimal value

	for(int i = 0; i < reverseValue.size(); i++) {//for
		temp = showDec(reverseValue[i]);

		decimalNum += (	(pow(16, i)) * temp	);
	}//for

	return decimalNum;
}//toDecimal
