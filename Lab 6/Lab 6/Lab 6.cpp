//Author: Nick Watson
//Class: CS 215
//Date: 2/13/2022
//Project: Lab 6
//Program name: Lab 6
//Purpose: TO create a program that creates a sum of inputed number. error checks inputs
//Last Edit: 2/17/2022

/*
 * Course: CS215-00x
 * Project: Lab6 (as part of Project 1)
 * Purpose: It focuses on testing the defintion of function named computer_play
 *          the computer takes either “smart” move or “non-smart” move, respectively.
 *          Under “smart-move” mode, the computer needs to make the following legal move to
 *                win the game: take off enough marbles to make the size of the remaining pile
 *                a power of two minus one (1, 3, 7, 15, 31 are some examples of the power of two minus 1)
 *                if the current pile size is not one of those power of two minus 1.
 *                When the current pile size is already a 2’s power – 1, make a random move
 *                taking at least one but at most half of the marbles.
 *          On the other hand, when the computer is under “non-smart-move” mode,
 *                the computer makes a random legal move: taking at least one but at most half of the marbles.
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10; // for layout purpose


// display marbles on the pile
void printMarbles(int pile);

// represent the legal move when it is the computer's turn to play the game
void computer_play(int& pile, bool smart);

int main()
{
    cout << "*****************************************************" << endl;
    cout << "*                 The game of Nim                   *" << endl;
    cout << "*    It demostrates two examples of the computer    *" << endl;
    cout << "*    under smart-move or non-smart-move mode        *" << endl;
    cout << "*****************************************************" << endl;

    // "hard-code" pile size for testing purpose
    // Testing case 1: the computer plays under smart-move mode:
    int pile = 20;
    // demonstrate the computer under smart-move mode
    bool smart = true;
    cout << "Testing case 1: " << endl;
    cout << "The computer will play smart." << endl;

    //use playCount to "fake" taking a turn between the computer and the player
    //after the loop, if playCount is even, it means it is computer's turn to take the last marble
    //                if playCount is odd, it means it is the player's turn to take the last marble
    int playCount = 0;
    while (pile > 1)
    {
        printMarbles(pile);
        computer_play(pile, smart);
        playCount++;
    }

    if (playCount % 2 == 0)
        cout << "The computer takes the last marble!" << endl;
    else
        cout << "The computer leaves the last marble for you:)" << endl;

    // Testing case 2: the computer plays under non-smart-move mode:
    pile = 5;
    // demonstrate the computer under non-smart-move mode
    smart = false;
    cout << endl << endl << "Testing case 2: " << endl;
    cout << "The computer will not play smart." << endl;

    playCount = 0;   // reset playCount back to 0
    while (pile > 1)
    {
        printMarbles(pile);
        computer_play(pile, smart);
        playCount++;
    }

    if (playCount % 2 == 0) // shows winner results
        cout << "The computer takes the last marble!" << endl;
    else
        cout << "The computer leaves the last marble for you:)" << endl;


    return 0;
}

/*
 * It displays the marbles on the pile: the number of marbles depends on passing in parameter
 *@param pile int: representing how many marbles are on the pile to display
 *@return: void function
 */
void printMarbles(int pile)
{
    cout << endl << "There are " << pile << " marbles in the pile." << endl;
    for (int i = 0; i < pile; i++)
        cout << setw(WIDTH) << MARBLE << endl;
}
void computer_play(int& pile, bool smart)
{
    int Powermath = (pile) + 1;// initial values
    int twohold = 1;
    int hold;
    int i = 0;
    int j = 0;
    int rantake;
    int  remov = (rand() % (pile / 2)); //randomizer for computer +- the required value under smart
    cout << "Computer plays:" << endl;
    if (smart == true){
        srand(time(0)); //reinitialize rand so it works properly
        while (1==1) { // does power of 2 minus one math
            while (1 == 1) {
                twohold = twohold * 2; // power of two counter
                j++; // counting 2^n power
                if (pile <= 3) { // fixes under 3 number issue so the computer doesn't take more than half
                    remov = 1;
                    break;
                }
                if (Powermath - twohold <0){ //makes sure value doesn't get negative. 
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
        cout << "The computer takes " << rantake<< " marbles." << endl; //displays amount taken

    }
     
        
}


