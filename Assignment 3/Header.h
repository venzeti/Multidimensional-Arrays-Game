#ifndef TICTACHEADER_H_
#define TICTACHEADER_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono_literals;


void DisplayHeader();
/******************************************************************************
* OutputInstruct
* This function outputs instructions to the users. There are no input
* or output parameters for this function as it only displays text to
* the screen.
*
* RETURNS: nothing
* Displays the instructions to the user
*****************************************************************************/
void OutputInstruct(); // OUT - Instructions
/******************************************************************************
* MainMenu
* This function outputs the menu that is available for the game. This will take
* in a letter and will progress depending on what they choose.
*
* RETURNS: the option for the rest of the game
* Displays the main menu to the user
*****************************************************************************/
char MainMenu(char& option, string& playerX, string& playerO);
/******************************************************************************
* InitBoard
* This function initializes each spot in the board to a space ' '.
*
* RETURNS: Board initialized with all spaces
*****************************************************************************/
void InitBoard(char boardAr[][3]); // OUT - tic tac toe board
/******************************************************************************
* DisplayBoard
* This function outputs the tic tac toe board including the tokens
* played in the proper format (as described below).
*
*	1		 2	    	3
* [1][1] | [1][2] | [1][3]
*        |		  |
* 1      |		  |
*        |        |
* --------------------------
* [2][1] | [2][2] | [2][3]
*        |        |
* 2      |        |
*        |        |
* --------------------------
* [3][1] | [3][2] | [3][3]
*        |        |
* 3      |        |
*        |        |
*
* RETURNS: nothing
* outputs the current state of the board
*****************************************************************************/
void DisplayBoard(const char boardAr[][3]); // IN - tic tac toe board
/******************************************************************************
* GetPlayers
* This function prompts the user and gets the input for the players� names.
* playerX will always contain the name of the player that is using the X token.
* playerO will always contain the name of the player that is using the O token.
*
* RETURNS: the players names through the variables playerX and playerO.
*****************************************************************************/
void GetPlayers(string& playerX, // OUT - player X�s name
	string& playerO); // OUT - player O�x name
/******************************************************************************
* RunGame
* This function will hold the main components of the game.
*
* RETURNS: nothing; runs it all through parameters
* Displays entire game
*****************************************************************************/
void RunGame(char boardArray[][3], char option, string& playerX, string& playerO);
/******************************************************************************
* GetAndCheckInp
* This will function get the input from the user and use that accordingly.
*
* RETURNS: nothing; runs it all through parameters
*****************************************************************************/
void GetAndCheckInp(char boardArr[][3], char token, string playerX, string playerO);
/******************************************************************************
* GetAndCheckInpComputer
* This function will allow the player to play with a computer.
*
* RETURNS: nothing; runs it all through parameters
*****************************************************************************/
void GetAndCheckInpComputer(char boardArr[][3], char token, string playerX, string playerO);
/******************************************************************************
* SwitchToken
* This function switches the active player.
* It takes in a parameter representing the current player's token
* as a character value (either an X or an O) and returns the opposite.
* For example, if this function receives an X it returns an 0. If it
* receives and O it returns and X.
*
* RETURNS: the token opposite of the one in which it receives.
*****************************************************************************/
char SwitchToken(char token); // IN - current player�s token ('X' or 'O')
/******************************************************************************
* CheckWin
* This function checks to see if either player has won. Once it is
* possible for a win condition to exist, this should run after each a
* player makes a play.
*
* RETURNS the character value of the player that won or a value that
* indicates a tie.
*****************************************************************************/
char CheckWin(const char boardAr[][3]); // IN - tic tac toe board
/******************************************************************************
* OutputWinner
* This function receives as input a character indicating which player won
* or if the game was a tie and outputs an appropriate message. This function
* does not return anything as it simply outputs the appropriate message to
* the screen.
*
* RETURNS: nothing
* � Displays the winner�s name
*****************************************************************************/
void OutputWinner(char whoWon, // IN - represents the winner or a value
 // indicating a tied game.
	string playerX, // OUT - player X�s name
	string playerO); // OUT - player O�x name

#endif /* TICTACHEADER_H_ */

// Start of OutputInstruct
void OutputInstruct() {
	// Brief welcome
	cout << "Hello and welcome to Tic-Tac-Toe!\n\n";
	this_thread::sleep_for(2s);
	cout << "Here, you can choose to end the program, set your name, decide"
		 << " if you want to play against another\nplayer (Two player mode) or versus the "
		 << "computer (One Player Mode)."
	   	 << "\n\n\n"
		 << "You can type what location you want to move to like this:"
		 << "\n\n\"Oscar's turn! What\'s your play?: 3 3\"\n\n"
		 << "This will move your character to the location the 3rd row and 3rd column\n\n\n";
} // End of OutputInstruct

// Start of MainMenu
char MainMenu(char& option, string& playerX, string& playerO) {
	int runOnce = 0;
	bool menu = true;
	while (menu) {
		if (runOnce == 0) {
			cout << "\t[ MAIN MENU: ]\n\n" << "A) Exit\n\nB) Set Player Names\n\nC) Play in Two Player Mode\n\n"
				<< "D) Play in One Player Mode\n\nEnter an option: ";
			cin >> option;
		} else {
			cout << "\t[ MAIN MENU: ]\n\n" << "A) Exit\n\nB) Change Player Names\n\nC) Play in Two Player Mode\n\n"
				<< "D) Play in One Player Mode\n\nEnter an option: ";
			cin >> option;
		}
		if (option == 'a' || option == 'A') {
			system("cls");
			cout << "Thank you for using my program.\n\n";
			return option;
			menu = false;
		}
		else if (option == 'b' || option == 'B') {
			GetPlayers(playerX, playerO);
			runOnce++;
		}
		else if (option == 'c' || option == 'C') {
			return option;
			menu = false;
		}
		else if (option == 'd' || option == 'D') {
			return option;
			menu = false;
		}
	}
	
} // End of MainMenu

// Start of GetPlayers
void GetPlayers(string& playerX, string& playerO) {
	system("cls");
	cout << "Enter the name for player X : ";
	cin >> playerX;
	cout << endl;
	cout << "Enter the name for player O : ";
	cin >> playerO;
	cout << endl << endl;
} // End of GetPlayers

// Start of InitBoard
void InitBoard(char boardArr[][3]) {
	for (int i = 0; i <= 2; i++) {
		for (int x = 0; x <= 2; x++) {
			boardArr[i][x] = ' ';
		}
	}
} // End of InitBoard

// Start of GetAndCheckInp
void GetAndCheckInp(char boardArr[][3], char token, string playerX, string playerO) {
	int x, y;
	if (token == 'X') {
		cout << playerX << "'s turn! What's your play?: ";
		cin >> x >> y;
		x -= 1;
		y -= 1;
		cout << "X: " << x << " Y: " << y << endl << endl;
		boardArr[x][y] = 'X';
	}	else if (token == 'O') {
		cout << playerO << "'s turn! What's your play?: ";
		cin >> x >> y;
		x -= 1;
		y -= 1;
		cout << "X: " << x << " Y: " << y << endl << endl;
		boardArr[x][y] = 'O';
	}
} // End of GetAndCheckInp

// Start of GetAndCheckInpComputer
void GetAndCheckInpComputer(char boardArr[][3], char token, string playerX, string playerO) {
	int x, y;
	bool empty = true;
	if (token == 'X') {
		cout << playerX << "'s turn! What's your play?: ";
		cin >> x >> y;
		x -= 1;
		y -= 1;
		boardArr[x][y] = 'X';
	} else if (token == 'O') {
		cout << playerO << " is thinking...";
		this_thread::sleep_for(2s);
		while (empty) {
			x = rand() % 3;
			y = rand() % 3;
			if (x > 0) {
				x = (rand() % 3) * (rand() % 3);
				if (x > 2) {
					if ((x * (rand() % 3)) % 2 == 0) {
						x = 0;
					}
					else if ((x * ((rand() % 500) % (rand() % 500))) % 2 == 0) {
						x = 1;
					}
					else {
						x = 2;
					}
				}
			}
			if (y > 0) {
				y = (rand() % 3) * (rand() % 3);
				if (y > 2) {
					if ((y * (rand() % 3)) % 2 == 0) {
						y = 0;
					}
					else if ((y * ((rand() % 500) % (rand() % 500))) % 2 == 0) {
						y = 1;
					}
					else {
						y = 2;
					}
				}
			}
			if (boardArr[x][y] == ' ') {
				boardArr[x][y] = 'O';
				empty = false;
			} 
		}
	}
} // End of GetAndCheckInpComputer

// Start of SwitchToken
char SwitchToken(char token) {
	if (token == 'X') {
		token = 'O';
		return 'O';
	} else {
		token = 'X';
		return 'X';
	}
} // End of SwitchToken

// Start of CheckWin
char CheckWin(char boardArr[][3]) {

	// CHECKING FOR X
	// HORIZONTAL CHECKS :
	if (boardArr[0][0] == 'X' && boardArr[0][1] == 'X' && boardArr[0][2] == 'X') {
		return 'X';
	}
	else if (boardArr[1][0] == 'X' && boardArr[1][1] == 'X' && boardArr[1][2] == 'X') {
		return 'X';
	}
	else if (boardArr[2][0] == 'X' && boardArr[2][1] == 'X' && boardArr[2][2] == 'X') {
		return 'X';
	}

	// VERTICAL CHECKS :
	else if (boardArr[0][0] == 'X' && boardArr[1][0] == 'X' && boardArr[2][0] == 'X') {
		return 'X';
	}
	else if (boardArr[0][1] == 'X' && boardArr[1][1] == 'X' && boardArr[2][1] == 'X') {
		return 'X';
	}
	else if (boardArr[0][2] == 'X' && boardArr[1][2] == 'X' && boardArr[2][2] == 'X') {
		return 'X';
	}

	// DIAGONAL CHECKS :
	else if (boardArr[0][0] == 'X' && boardArr[1][1] == 'X' && boardArr[2][2] == 'X') {
		return 'X';
	}
	else if (boardArr[0][2] == 'X' && boardArr[1][1] == 'X' && boardArr[2][0] == 'X') {
		return 'X';
	}

	// CHECKING FOR O
	// HORIZONTAL CHECKS :
	else if (boardArr[0][0] == 'O' && boardArr[0][1] == 'O' && boardArr[0][2] == 'O') {
		return 'O';
	}
	else if (boardArr[1][0] == 'O' && boardArr[1][1] == 'O' && boardArr[1][2] == 'O') {
		return 'O';
	}
	else if (boardArr[2][0] == 'O' && boardArr[2][1] == 'O' && boardArr[2][2] == 'O') {
		return 'O';
	}

	// VERTICAL CHECKS :
	else if (boardArr[0][0] == 'O' && boardArr[1][0] == 'O' && boardArr[2][0] == 'O') {
		return 'O';
	}
	else if (boardArr[0][1] == 'O' && boardArr[1][1] == 'O' && boardArr[2][1] == 'O') {
		return 'O';
	}
	else if (boardArr[0][2] == 'O' && boardArr[1][2] == 'O' && boardArr[2][2] == 'O') {
		return 'O';
	}

	// DIAGONAL CHECKS :
	else if (boardArr[0][0] == 'O' && boardArr[1][1] == 'O' && boardArr[2][2] == 'O') {
		return 'O';
	}
	else if (boardArr[0][2] == 'O' && boardArr[1][1] == 'O' && boardArr[2][0] == 'O') {
		return 'O';
	} 

	// If the board is full, then it will return 't' for tie
	else {
		return 't';
	}
}  // End of CheckWin

// Start of OutputWinner
void OutputWinner(char whoWon, string playerX, string playerO) {
	if (whoWon == 'x' || whoWon == 'X') {
		cout << playerX << " has won the game! Congratulations!\n\n";
	}
	else if (whoWon == 'o' || whoWon == 'O') {
		cout << playerO << " has won the game! Congratulations!\n\n";
	}
	else if (whoWon == 't' || whoWon == 'T') {
		cout << "This is a tie game!\n\n";
	}
}

// Start of DisplayBoard
void DisplayBoard(const char boardAr[][3])
{
	// Variable initialized
	int row; 
	// Variable initialized
	int column;
	// Outputs the top bar
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n\n"; 
	// Start of for loop that will display the board
	for (row = 0; row < 3; row++)
	{
		// This will display each row
		cout << setw(7) << "[" << row + 1 << "][1] | " << "[" << row + 1;
		// This will display each row
		cout << "][2] | " << "[" << row + 1 << "][3]" << endl;
		// This will display each row
		cout << setw(14) << "|" << setw(9) << "|" << endl;
		// This will display each column
		for (column = 0; column < 3; column++)
		{
			// This will be display at the left of everything
			switch (column)
			{
				// This will display the right of the left column
			case 0: cout << row + 1 << setw(9) << boardAr[row][column];
				// This will seperate X and O
				cout << setw(4) << "|";
				break;
				// This will display on the right of the middle column
			case 1: cout << setw(4) << boardAr[row][column];
				// This will seperate X and O
				cout << setw(5) << "|";
				break;
				// This will show up on the left side of the board
			case 2: cout << setw(4) << boardAr[row][column] << endl;
				break;
				// If something failes, it will output an error message
			default: cout << "ERROR!\n\n";
			}
		}
		// Will display the pipes at the end of each column
		cout << setw(14) << "|" << setw(10) << "|\n";
		// An if statement that only runs two times
		if (row != 2)
		{
			// Splits the board twice
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl << endl;
} // End of DisplayBoard