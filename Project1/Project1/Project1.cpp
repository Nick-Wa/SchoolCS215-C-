//Author: Nick Watson
//Class: CS 215 section 008
//Date: 2/13/2022
//Project: project 1
//Program name: Nim
//Purpose: create a game
//Last Edit: 2/25/2022
//Notes: I sincerely tried to break this but it seems stable. Have a good weekend whoever is grading this.

#include <iostream> // libraries
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std; 

const int PILE_MAX = 50; // constants
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10; // for layout purpose
bool smart=true; //initializing value
int pile;

// display marbles on the pile
void printMarbles(int pile); // void function to print marbles left

// represent the legal move when it is the computer's turn to play the game
void computer_play(int& pile, bool smart); // computer plays smart/nonsmart

void player_play(int& pile); // Player input void function

int main() // main body
{
  
    cout << "*****************************************************" << endl; //beginning display
    cout << "*                 The game of Nim                   *" << endl;
    cout << "*   Players alternate taking at least one but at    *" << endl;
    cout << "*      most half of the marbles in the pile.        *" << endl;
    cout << "*   The player who takes the last marble loses.     *" << endl;
    cout << "*         It is written by Nick Watson              *" << endl;
    cout << "*        I hope you beat the computer :             *" << endl;
    cout << "*      No matter what, have a great day.            *" << endl;
    cout << "*****************************************************" << endl;


    bool smart;
    srand(time(0));
    pile = (rand() % 40) + 10;
    string answer;
    int whofirst; //true for person, false for comptuer
    srand(time(0));

    int ranpick = rand() % 2;
    int randif = rand() % 2;

        if (randif == 1) { //smart not smart randomizer
             smart = false;
            cout << "The computer will not play smart." << endl;
        }
        else if (randif == 0) { //smart not smart randomizer
             smart = true;
            cout << "The computer will play smart." << endl;
        }

        cout << "Coin flip to see he goes first" << endl;
        if (ranpick == 1) //order randomizer
        {
            whofirst = 1;
            cout << "You will play first." << endl;
        }
        else if (ranpick == 0) {
            whofirst = 0;
            cout << "The computer will play first" << endl;
        }

        int playCount; //initialize play count
        while (pile > 1)
        {
            if (whofirst == 1) { //call functions depending on the order of whos first
                printMarbles(pile);
                player_play(pile);
                if (pile == 1) {
                    playCount = 1;
             }
                printMarbles(pile);
                computer_play(pile, smart);
                if (pile == 1) {
                    playCount = 0;
                }
                
            }
            else {
                printMarbles(pile);
                computer_play(pile, smart);
                if (pile == 1) {
                    playCount = 0;
                }
                printMarbles(pile);
                player_play(pile);
                if (pile == 1) {
                    playCount = 1;
                }
                
            }
        }
        if (whofirst = true) { //who wins announcement
            if (playCount = 1)
                cout << "The computer takes the last marble!" << endl;
            else
                cout << "The computer leaves the last marble for you:)" << endl;
        }
        return 0;
    
    }
    /*
     * It displays the marbles on the pile: the number of marbles depends on passing in parameter
     *@param pile int: representing how many marbles are on the pile to display
     *@return: void function
     */
    void printMarbles(int pile){

        cout << endl << "There are " << pile << " marbles in the pile." << endl;
        for (int i = 0; i < pile; i++)
            cout << setw(WIDTH) << MARBLE << endl;
    }
  
 void computer_play(int& pile, bool smart){ // computer function defined

     int Powermath = (pile)+1;// initial values
     int twohold = 1;
     int hold;
     int i = 0;
     int j = 0;
     int rantake;
     int  remov = (rand() % (pile / 2)); //randomizer for computer +- the required value under smart
     cout << "Computer plays:" << endl;
     if (smart == true) {
         srand(time(0)); //reinitialize rand so it works properly
         while (1 == 1) { // does power of 2 minus one math
             while (1 == 1) {
                 twohold = twohold * 2; // power of two counter
                 j++; // counting 2^n power
                 if (pile <= 3) { // fixes under 3 number issue so the computer doesn't take more than half
                     remov = 1;
                     break;
                 }
                 if (Powermath - twohold < 0) { //makes sure value doesn't get negative. 
                     twohold = 1;
                     j--; // brings it back one to have the closest power of two
                     while (i < j) {
                         twohold = twohold * 2; //quick power of 2 math
                         i++;
                     }
                     remov = Powermath - twohold;// what the computer will take for marbles

                     break;
                 }
                 if (Powermath - twohold == 0) { // if initial count of marbles is already power of 2 minus 1
                     break;
                 }

             }
             pile = pile - remov; // take from the pile

             cout << "The computer takes " << remov << " marbles." << endl; //displays how many the computer took
             Powermath = pile + 1;
             break;
         }



     }
     if (smart == false) { // if computer isn't smart
         srand(time(0)); //reinitalizes the random counter
         rantake = rand() % (pile / 2) + 1; // checks 1- 1/2 of pile for a marble pull

         pile = pile - (rantake);
         cout << "The computer takes " << rantake << " marbles." << endl; //displays amount taken

     }


 }



void player_play(int& pile){ //player function

     int playerinput;
     string plystring;
     while (1 == 1) {
         cout << "Your play. You may take 1 to " << (pile / 2) << " marbles." << endl;
         cout << "You take:";
         cin >> playerinput;
         cin.ignore(10000, '\n'); // Ignore everything after the first input value "15 is my favorite number", to "15"

         if (cin.fail()) { //checks for incorrect input value (non integer)
             cin.clear(); // clears the error in the code
             getline(cin, plystring);
             playerinput = 0; //Resets Userinput value
             cout << "Incorrect input. Try again" << endl;
         }
         else if ((playerinput <= 0) | (playerinput > (pile / 2))) {
             cout << "Number must be between 1 and " << (pile / 2) << endl;
         }
         else { break; }
     }
     cout << "You will take " << playerinput << " from the pile." << endl;
     pile = pile - playerinput;
 }

