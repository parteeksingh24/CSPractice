//============================================================================
// Name        : FunWithStrings.cpp
// Author      : Parteek Singh
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>			//for setprecision()
using namespace std;

int 	length (const char []);
void 	reverse(char*);
int 	wordCount(const char*);
int 	wordCount(string);			//Overloaded version of the "wordCount" function
float 	avgLetters(const char*);

int main(void) {//main
	char str[] = "Hello";

	cout << length(str) << endl;
	reverse(str);

	char message[] = "Four score and seven years ago";
	cout << wordCount(message) << endl;						//Will print: 6

	string text = "C++ is very fun!";
	cout << wordCount(text)		<< endl;				//Will call the overloaded string function, print 4

	char sentence[] = "Let's see how many words we have on average here!";
	cout << setprecision(1) << fixed << avgLetters(sentence) << endl; 	//Should display 3.8
			//setprecision(1) and fixed limits answer to 1 value after the decimal
		//without fixed, we would have 1 value total (including both whole and fractional parts)
		//with only fixed, it simply converts to fixed fixed point notation, so it converts exponents to floating point


	cout << "Program ending, have a nice day!" << endl;
	return 0;
}//main

/* FUNCTIONS:
 * ====================================================
 */
int length(const char word[]) {//stringLength
	int counter = 0;

	while(word[counter] != '\0') {//while
		counter++;
	}//while

	return counter;
}//stringLength

void reverse(char* str) {//reverse
	int position = length(str) - 1;	//Start at the last character of c-string
										//Calls the "length" function found in main

	while(position >= 0) {//while
		cout << *(str + position) << " ";
		position--;
	}//while
	cout << endl;
}///reverse

int wordCount(const char* word) {//wordCount (c-string)
	int counter = 0;

	while(*word != '\0') {//while
		if(isspace(*word) == true) {//if
			counter++;
		}//if

		word++;				//Increment the char pointer through the c-string (array)
	}//while

	return counter + 1;		//The # of words will be one more than the # of spaces
}//wordCount (c-string)

int wordCount(string word) {//wordCount (string)
//We can convert our string to a c-string and use the wordCount function above:
	const char* ptr = word.c_str();	/* NOTE:
										the c_str() function returns a constant char,
										so we must make sure the parameter of our
										original "wordCount" function is also a const char.
									*/

	return wordCount(ptr);


/* For the independent function, see below:
	int counter = 0;

	for(int i = 0; i < word.size(); i++) {//for
		if(isspace(word[i]) == true) {//if
			counter++;
		}//if
	}//for

	return counter;
*/
}//wordCount (string)

float avgLetters(const char* text) {//averageLetterCount
//average number of letters in each word.
	int words = wordCount(text);
	int letters = 0;
	float average = 0.0;

	for(int i = 0; i < length(text); i++) {//for
		if(isalpha(text[i]) == true) {//if
			letters++;
		}//if
	}//for

	average = (static_cast<float>(letters)) / words;
		/* This is done to ensure we are using floating point division, not integer division
			(if at least one of the numbers is a floating point number (float/double), it will
			output the answer as a float/double as well).
		*/
	return average;
}//averageLetterCount
