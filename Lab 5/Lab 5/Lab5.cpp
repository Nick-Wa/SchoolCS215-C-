//Author: Nick Watson
//Class: CS 215
//Date: 2/13/2022
//Project: Lab 5
//Program name: Lab 5
//Purpose: TO create a program that creates a sum of inputed number. error checks inputs
//Last Edit: 2/17/2022

#include <iostream> //database
#include <string>

using namespace std;

int Userinput=0; //Initial Values
int Sum=0;
string str_input;
double Powermath;
bool programbreaker=true;
int main() {

	while (1 == 1) { // Main loop
		

		while (1 == 1) {// breakable loop
			cout << "Please enter a series of positive numbers, then type(Q or q) to process :" << endl;
			cin >> Userinput;
			cin.ignore(10000, '\n'); // Ignore everything after the first input value "15 is my favorite number", to "15"
			Powermath = (Userinput + 1); //inital value for the power of 2 minus 1
			if (cin.fail()) { //checks for incorrect input value (non integer)
				cin.clear(); // clears the error in the code
				getline(cin, str_input);
				Userinput = 0; //Resets Userinput value
				if (str_input == "q" or str_input == "Q") { // stops sum gives total sum from other valuds
					cout << "Have a great day!" << endl; 
					cout << "The sum of all user input is: " << Sum << endl;
					programbreaker = false;
					break;
				}
				else {
					cout << "Invalid Input, Please try again..." << endl;// error message for string
					break;

				}
				
				break;
			}


			if (Userinput < 0) { // tests for negative
				cout << "Please input a positive integer instead..." << endl;
				break;
			}
			Sum = Userinput + Sum; // sum equation
			cout << "The corresponding element for the cumulative total sequence is : " << Sum << endl;
			while (Powermath >= 2) { // does power of 2 minus one math/
				Powermath = Powermath / 2;
			}

			if (Powermath == 1) { // checks value
				cout << Userinput << " is a Power of Two Minus One!" << endl;
			}
			else { cout << Userinput << " is not a Power of Two Minus One!" << endl; }
		}
		if (programbreaker == false) {
			break;
		}
	}
		

	
		 
	 return 0;
}