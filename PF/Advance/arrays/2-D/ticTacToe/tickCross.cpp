/**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-08-06.

  TIME: 9:33 PM.
*/
#include <iostream>
using namespace std;

const char Xs_Turn = 'X';
const char Os_Turn = 'O';

const char boardSize = 3;
char board[boardSize][boardSize] = { {' ', ' ', ' '},
                                     {' ', ' ', ' '},
                                     {' ', ' ', ' '} };

void displayBoard(char board[boardSize][boardSize]) {
    cout << "TIC TAC TOE" << endl;
    for (int i_R = 0; i_R < boardSize; i_R++) {
        for (int j_R = 0; j_R < boardSize; j_R++) {
            cout << "[" << board[i_R][j_R] << "] ";
        }
        cout << endl;
    }
}
void switchPlayer(char &player) {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}


bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return true;
    return false;
}

int main() {
    int row,col;
    displayBoard(board);
    char player = 'X';
    for (int i=1 ; i<=9 ; i++) {
        cout << player << " turns:\n";
        cout << "Enter location: (row by col)";
        cin >> row >> col;
        if (player == 'X') {
            if(board[row][col] == ' ') {
                board[row][col] = 'X';
            } else {
                cout << "already selected" ;
            }
        } else {
            if(board[row][col] == ' ') {
                board[row][col] = 'O';
            } else {
                cout << "alredy slected change location" ;
            }
        }

        displayBoard(board);
        switchPlayer( player);
        if (checkWin()){

            cout << " you win ";
            break;
        }

    }
        return 0;
}
