/*
Project: TicTacToe
Description: 2-player Tic-Tac-Toe game
Author: Ashvika Singhal
Sure
 */

#include <iostream>
#include <cstring>
using namespace std;

const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 3;
const int O_TURN = 4;

void printBoard (int board[3][3]);
bool checkWin (int board[3][3], int player);
bool checkTie (int board[3][3]);

int main(){
  //creating board
  int board[3][3];
  int turn = X_TURN;
  int player = X_MOVE;
  int xwins = 0;
  int owins = 0;
  int ties = 0;
  for (int i = 0; i<3; i++){
    for (int j = 0; j<3; j++){
      board[i][j] = BLANK;
    }
  }
  printBoard(board);

    bool stillPlaying = true;

  while (stillPlaying == true){
    cout << "Enter row column" << endl;

    char input [5];
    cin.getline (input, 5);

    cout << input << endl;

    bool isValid = false;
    bool tempValid = false;
    int row;
    int column;

    while (isValid == false){
      if  (strlen(input) == 2) {                    
	if ((input[0] >= 'A') && (input[0] <= 'C')){
	  if ((input[1] >= '1') && (input [1] <= '3')){
	    //cout << "input not valid second" << endl;
	    tempValid = true;
    }
	}
      }

      if (tempValid == true){
	 if (input[0] == 'A'){
         row = 0;
       }
       else if (input[0] == 'B'){
         row = 1;
     }
     else if (input[0] == 'C'){
       row = 2;
     }
 
     if (input[1] == '1'){
       column = 0;
     }
     else if (input[1] == '2'){
       column = 1;
     }
     else if (input[1] == '3'){
       column = 2;
     }
 if (board[row][column] == BLANK){ 
	  isValid = true;
	}
      else {
	isValid = false;
      }

      }
      
    if (isValid == false){
      cout << "input not valid whole" << endl;
      cout << "try again. Uppercase Letter and Number no spaces" << endl;
      cin.getline(input, 5);
      }

    }
    
    if (isValid == true){

    if (turn == X_TURN){
      board[row][column] = X_MOVE;
      player = X_MOVE;
      if (checkWin(board, player) == true){
	xwins++;
	cout << "X won this game" << endl;
	cout << "X Wins: " << xwins << endl;
	cout << "O Wins: " << owins << endl;
	cout << "Ties: " << ties << endl;
	cout << "Type y to play again and type n to end game" << endl;
	char playAgain;
        cin >> playAgain;
	cin.ignore(10, '\n');
        if (playAgain == 'n'){
        stillPlaying = false;
        }
	else if (playAgain == 'y'){
	 for (int i = 0; i<3; i++){
           for (int j = 0; j<3; j++){
             board[i][j] = BLANK;
           }
         }
	 //
        }
      }

       else if (checkTie(board) == true){
	 ties++;
	 cout << "This game was a tie." << endl;
        cout << "X Wins: " << xwins << endl;
        cout << "O Wins: " << owins << endl;
        cout << "Ties: " << ties << endl;
        cout << "Type y to play again and type n to end game" << endl;
        char playAgain;
        cin >> playAgain;
        cin.ignore(10, '\n');
        if (playAgain == 'n'){
          stillPlaying = false;
        }
        else if (playAgain == 'y'){
         for (int i = 0; i<3; i++){
           for (int j = 0; j<3; j++){
             board[i][j] = BLANK;
           }
         }
         //
        }

       }
      
      turn = O_TURN;
      player = O_MOVE;
    }
    else if (turn == O_TURN){
      board[row][column] = O_MOVE;
      player = O_MOVE;
      if (checkWin(board, player) == true) {
	owins++;
	cout << "O won this game" << endl;
	cout << "X Wins: " << xwins << endl;
	cout << "O Wins: " << owins << endl;
        cout << "Ties: " << ties << endl;
        cout << "Type y to play again and type n to end game" << endl;
	char playAgain;
	cin >> playAgain;
	cin.ignore(10, '\n');
	if (playAgain == 'n'){
	  stillPlaying = false;
	}
	else if (playAgain == 'y'){
	 for (int i = 0; i<3; i++){
	   for (int j = 0; j<3; j++){
	     board[i][j] = BLANK;
	   }
	 }
	 //
	}
      }
      else if (checkTie(board) == true){
	ties++;
	cout << "This game was a tie." << endl;
        cout << "X Wins: " << xwins << endl;
        cout << "O Wins: " << owins << endl;
        cout << "Ties: " << ties << endl;
        cout << "Type y to play again and type n to end game" << endl;
        char playAgain;
        cin >> playAgain;
        cin.ignore(10, '\n');
        if (playAgain == 'n'){
          stillPlaying = false;
        }
        else if (playAgain == 'y'){
         for (int i = 0; i<3; i++){
           for (int j = 0; j<3; j++){
             board[i][j] = BLANK;
           }
         }
         //
        }

      }
      turn = X_TURN;
      player - X_MOVE;
    }

    printBoard(board);

    }
}
}

void printBoard (int board [3][3]){
  cout << " \t1\t2\t3" << endl;
  for (int i = 0; i < 3; i++){
    cout << (char)('A' + i) << '\t';
      for (int j = 0; j < 3; j++){
	if (board[i][j] == BLANK){
	  cout << "\t"; //ouput += idk
        }
	else if (board[i][j] == X_MOVE){
	  cout << "X\t";
	}
	else if (board[i][j] == O_MOVE){
	  cout << "O\t";
	}
      }
      cout << endl;
  }
  
}

bool checkWin(int board[3][3], int player){
//rows
  if (board[0][0]==player && board[0][1]==player && board[0][2]==player){
    return true;
  }
if (board[1][0]==player && board[1][1]==player && board[1][2]==player) {
  return true;
 }
if (board[2][0]==player && board[2][1]==player && board[2][2]==player){ 
  return true;
 }

//columns
if (board[0][0]==player && board[1][0]==player && board[2][0]==player){ 
  return true;
 }
   if(board[0][1]==player && board[1][1]==player && board[2][1]==player) {
     return true;
   }
   if (board[0][2]==player && board[1][2]==player && board[2][2]==player){
     return true;
   }

//diagonals
if (board[0][0]==player && board[1][1]==player && board[2][2]==player){
  return true;
 }
 if (board[2][0]==player && board[1][1]==player && board[0][2]==player){
  return true;
}
return false;

}

bool checkTie(int board[3][3]) {
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (board[i][j]==BLANK){
	return false;
      }
    }
  }
  return true;
}
