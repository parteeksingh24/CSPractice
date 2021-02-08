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
#include <map>							//For the menu choice entered by the user
using namespace std;					//The standard namespace is used (for cin, cout, etc)

enum Choices {//menuOptions
	notDefined,
	option1,
	option2,
	option3,
	option4,
	endProgram
};

map<string, Choices> menu;

//FUNCTION PROTOTYPES:
	void	initialize(void);			//Sets the map, "menu", to hold the valid menu choices
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
	string 			menuChoice	= "";	//Holds the user's choice for the main menu (used in switch statement)
	const string 	EXIT_CODE 	= "9";	//Per the instructions, if the number 9 is entered, exit the program
	string 			decimalNum	= "";	//Used for the decimal conversions to binary and hex, respectively
	string			userInput	= "";	//Stores the binary or hex number entered by user

//START OF PROGRAM:
	initialize();						//Set up the map so that the valid menu options are stored in the enum

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
		getline(cin, menuChoice);

	//To prevent the user from typing in a string of letters for the menu choice
		while(cin.fail() == true) {//while
			//cout << "ERROR: Please enter a valid menu option." << endl;
				//NOTE: this is done by the default case in the switch statement!
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}//while

		/*
		 	NOTE: The clear function here will clear any error flags caused if std::cin
		 	 	 	 was not able to read in the input correctly.
		 	 	   The ignore function will remove any invalid inputs from the input/read
		 	 	   buffer, which caused the error flag in the first place. With the
		 	 	   arguments given on line 74, cin.ignore() will ignore the next 25
		 	 	   characters it sees, OR all the characters until the newline character,
		 	 	   \n, shall be ignored.
		 */

		//Determine which function to run based on given input, using a switch statement
		switch(menu[menuChoice]) {//switch
		case option1:
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

				/*
				 NOTE: The first two catch blocks are for catching exceptions from
						 stoi(), used inside the "decimalToBinary" function. If the string
						 entered is not all number values, like say "123xyz", for example,
						 the stoi() function will throw an invalid_argument error/exception
						 and will be caught by the first catch block.
					   The second catch block is for any string input that can be converted
						 by stoi(), but is too large of a value (in both the positive and
						 negative directions) to be held by an integer in C++. This will
						 throw an out_of_range error.
					   The last catch block, which catches exceptions thrown from inside
						 the "decimalToBinary" function, accounts for errors if the user
						 enters a valid string that can be converted by stoi(), but is
						 either a negative integer, or is longer than 8 digits, as
						 specified by the project instructions.
				*/

			break;
		case option2:
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

				/*
				 NOTE: The catch block will handle one of 2 exceptions thrown from inside
						 the "binaryToDecimal" function. The first is if the string
						 input is not a binary number (if it contains anything other
						 than 1s and 0s). The second exception is if the binary number
						 entered is longer than 8 bits, as specified by the project
						 requirements.
				*/


			break;
		case option3:
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

				/*
			 	 NOTE: The first two catch blocks are for catching exceptions from
					 stoi(), used inside the "decimalToHex" function. If the string
					 entered does *not* contain only numerical values, like "12abcd",
					 the stoi() function will throw an invalid_argument error/exception
					 and will be caught by the first catch block.
				   The second catch block is for any string input that can be converted
					 by stoi(), but is too large of a value to be held by an integer
					 in C++. This will throw an out_of_range error.
				   The last catch block, which catches exceptions thrown from inside
					 the "decimalToHex" function, accounts for errors if the user
					 enters a valid string that can be converted by stoi(), but is
					 either a negative integer, or is longer than 8 digits, as
					 specified by the project instructions.
			 */

			break;
		case option4:
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

				/*
				 NOTE: The catch block will handle one of 2 exceptions thrown from inside
						 the "hexToDecimal" function. The first is if the string
						 input is not a hexadecimal number (if it contains anything other
						 than the numbers 0-9, and the letters a-f, *case sensitive*
						 as required by the project instructions).
					   The second exception is if the hexadecimal number
						 entered is longer than 4 bits, as specified by the project
						 requirements.
				*/

			break;
		case endProgram:
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
void initialize(void) {//initializeMenu
	menu["1"] = option1;
	menu["2"] = option2;
	menu["3"] = option3;
	menu["4"] = option4;
	menu["9"] = endProgram;
}//initializeMenu

string reverse(string input) {//reverseAGivenString
/* This function takes in a string and returns the
	reversed version of that string.
*/
	string returnStr = "";	//This is where we store the reversed string

	for(int i = input.size() - 1; i >= 0; i--) {//for (prints from end of string to beginning)
		returnStr += input[i];
				/*
				   Adds each character of original string to reversed string.
					Since we're looping "backwards", this will start from the
					end of the original string, and keep adding the current
					character to a new string, until we reach the front of
					the original string.
				*/
	}//for

	return returnStr;		//Return the reversed string
}//reverseAGivenString

int	showDec(char hexValue) {//showDecimalValue
/* This function takes in a hexadecimal value (0-9, a-f) and
	converts it into its decimal equivalent.
*/
	int returnVal = 0;		//The integer that corresponds to the given hex value

	if(hexValue >= '0' && hexValue <= '9') {//if
		returnVal = hexValue - 48;

				/*
				   If the character has a  value between 48 and 57 on the standard
				    ASCII table, it is a number from 0 to 9. Subtracting off the value 48,
				    which is how the character '0' is stored, gives us a value
				    *for our returnVal integer* that is between 0 and 9.
				   So, this allows us to go from characters in the ASCII table, to decimal
				    values we can store in our integer variable.
				 */
	}//if
	else {//else
		returnVal = hexValue - 87;
				/*
				   If the character has a  value between 97 and 102 on the standard
					ASCII table, it is a letter from a to f. Subtracting off the value 87,
					gives us an integer value from 10 to 15, which are exactly
					the same numbers that are mapped to the letters a-f in the
					hexadecimal number system. For example, 0-9 in decimal are 0-9 in hex,
					but starting from the number 10 in decimal, the equivalent hexadecimal
					value is the letter a. Then 11 gets mapped to b, 12 to the letter c, etc.
				   So, if the "hexValue" is a character from a-f, and we take away the number
				   87, we will get decimal values from 10-15, which are the decimal
				   equivalents.
				*/

	}//else

	return returnVal;		//Return the integer value after converting
}//showDecimalValue

bool checkBinary(string binaryNum) {//checkIfBinary
/* This function takes in a string input and checks if it is
	a valid binary number. Hence, it checks whether or not the input
	is comprised of only 1s and 0s.
*/
	bool isBinary = true;	//Set the value to true initially, and see if any character changes this

	for(unsigned int i = 0; i < binaryNum.size(); i++) {//for
		if(binaryNum[i] != '0' && binaryNum[i] != '1') {//if
			isBinary = false;
		}//if
							//If there's a character in the string that is not a 0 or 1, it is not binary
	}//for

	return isBinary;		//Return the boolean variable (true or false) depending on the check above
}//checkIfBinary

bool checkHexadecimal(string hexNum) {//checkIfHex
/* This function takes in a string input and checks if it is
	a valid hexadecimal number. Hence, it checks whether or not the input
	is comprised of only the numbers 0-9, and the letters a-f, *case sensitive*.
*/
	bool result = true;		//Set the result to be true, and check if any character changes this

	for(unsigned int i = 0; i < hexNum.size(); i++) {//for
		if(showDec(hexNum[i]) < 0 || showDec(hexNum[i]) > 15) {//if
			result = false;
			break;
							/*
							  If there is a character that does not have a decimal representation
							   between 0 and 15 (which is true for all hex values, 0-9 and a-f)
							   then the check's result will be false and we will break out of the loop,
							   since finding even one non-hexadecimal value is enough for the entire
							   string to be an invalid input.
							*/
		}//if
		else {//else
			continue;		/*
							  If the current character is a valid hexadecimal value, continue the
							   loop (if the counter "i" is still less than the string's size)
							   and check the next character of the string.
							*/
		}//else
	}//for

	return result;			//After looping through the entire input, return the result of the check(T/F)
}//checkIfHex

string	decimalToBinary(string str) {//decToBinary
/* This function takes in a string input, checking if it's a valid decimal number,
  	and converts the input to a binary number.
   In this project, a valid decimal number is a non-negative (0 and above) value
    that is less than 8 digits in length.
   Note that this function uses the stoi() conversion function, to convert the
    given string to an integer value, so it can be used to do calculations.
*/
	string 	binaryNum 	= "";			//The converted number (in binary form) to be returned
	int 	decNum		= stoi(str);	//The integer version of the given input, used in calculations
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
		int remainder = 0;				//Will store the remainder when dividing "decNum" by 2 repeatedly

		do {//do
			remainder = decNum % 2;		//Since we are dividing by 2, this will be either 0 or 1
											//(based on the Quotient Remainder Theorem!)
			binaryNum += to_string(remainder);
			decNum = decNum / 2;		/*
									      Will truncate any decimal/"floating point" part by default.
									      Hence, it will keep track of the quotient after division,
									       which is the standard method in converting decimal to binary!
										*/
		}//do
		while(decNum != 0);				/*
										  The loop will continue until the quotient is 0,
										   since this will indicate when we've divided our quotient
										   as much as possible.
										*/
	}//else

	return reverse(binaryNum);		//To display the binary number starting from the most significant bit
}//decToBinary

int	binaryToDecimal(string inputStr) {//binaryToDecimal
/* This function takes in a string input, checking if it's a valid binary number,
	and converts the input to a decimal number.
   In this project, a valid binary number is string of only 1s and 0s,
	that is less than 8 digits in length.
*/
	string 	binaryNum 	= "";		//Will hold the binary input, granted it is a valid binary string
	int 	decimalNum	= 0;		//The converted number in decimal form (to be returned)
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
		binaryNum		= reverse(inputStr);
									/*
									  This allow us to start from least significant bit (LSB)
									   and increment *up* by 1 each time in the following for loop.
									  This way, we start at the bit that represents the lowest exponent
									   value (2^0) in binary, and increments up to subsequent values
									   of 2, for subsequent binary digits (bits).
									*/

		int temp		= 0;		/*
									  This will hold the numerical value of each character in the
									   string, based on the standard ASCII table, so we can add the
									   resulting integer values to our decimalNum value, and return
									   the final result at the end of the function.
									*/

		for(unsigned int i = 0; i < binaryNum.size(); i++) {//for
			temp = binaryNum[i] - '0';
				/*
				 Converts the ASCII value of the char to its numerical value.
				 To convert the ASCII value to an integer value, we can subtract the value of
				  the zero character, '0'.
				 Recall that the ASCII character '0' is 48 in decimal, and a digit like '9' is 57,
				 so when we subtract by the '0', we are essentially subtracting the difference
				 in decimal form.

				 Basically, it figures out the distance from '0'!
				 */

			decimalNum 	+= ( (pow(2, i)) * temp );	//Multiply by the corresponding power of 2
														//(based on how the conversion is typically done)
		}//for
	}//else

	return decimalNum;				//Return the final decimal result
}//binaryToDecimal

string	decimalToHex(string str) {//toHexadecimal
/* This function takes in a string input, checking if it's a valid decimal number,
	and converts the input to a hexadecimal number.
   In this project, a valid decimal number is a non-negative (0 and above) value
	that is less than 8 digits in length.
   Note that this function uses the stoi() conversion function, to convert the
	given string to an integer value, so it can be used to do calculations.
*/
	string 	hexNum		= "";			//The converted hexadecimal value (to be returned at end)
	int 	decNum		= stoi(str);	//Converts the given string to an int (used in calculations below)
	int		remainder	= 0;			/*
										  Whatever remainder we get when dividing our number by 16,
										   the base, we will add to the hexNum.
										*/

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
		while(decNum != 0) {//while
			remainder 	= decNum % 16;	//Holds the remainder after division

			if(remainder < 10) {//if
				//To get values between 48 and 57 in ASCII table (the values 0-9)
				hexNum.push_back(remainder + 48);
			}//if
			else {//else
				//To get the values of lower case letters in ASCII table
					//(since remainder will be 10 and above)
				hexNum.push_back(remainder + 87);
			}//else

			decNum 		= decNum / 16;	//Divide the current decimal number, and loop again if needed
		}//while
	}//else

	return reverse(hexNum);				//To display starting from the most significant digit
}//toHexadecimal

int	hexToDecimal(string hexValue) {//hexToDecimal
/* This function takes in a string input, checking if it's a valid hex number,
	and converts the input to a decimal number.
   In this project, a valid hexadecimal number consists of the numbers 0-9,
    and the letters a-f (case sensitive), that is less than 4 digits long.
*/
	string 	reverseValue 	= "";	//Will hold the reversed hex number, given it's a valid input
	int 	decimalNum		= 0; 	//Holds the running total for the decimal value
	string	badInput		= "";	//Holds any string exceptions, if the input is invalid

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
		reverseValue = reverse(hexValue);
									//Allows our for loop to increment up
										//(starting from least significant digit)
		int temp = 0;
									//Stores the converted hex values as their integer values
										//(based on ASCII table)
									//(will store a number for each hex character in the given string)

		for(unsigned int i 	= 0; i < reverseValue.size(); i++) {//for
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

	return decimalNum;				//Return the integer total after all calculations
}//hexToDecimal
