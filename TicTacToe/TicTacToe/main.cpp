//
//  main.cpp
//  TicTacToe
//
//  Created by Adhiraj Pathak on 8/12/19.
//  Copyright © 2019 Adhiraj Pathak. All rights reserved.
//

#include <iostream>
#include <ncurses.h>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row, col;
bool draw = false; //there is no draw at the starting of the game

void display_board() {
    system("clear");
    cout << "    T I C K   T A C   T O E   G A M E" << endl;
    cout << "\tPlayer1 [X] \n \tPlayer2 [0]\n\n";
    
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout << "\t\t     |     |     \n";
}

void player_turn() {
    int choice;
    
    if(turn == 'X')
    cout << "\n\tPlayer1 [X] turn: ";
    
    if(turn == 'O')
    cout << "\n\tPlayer2 [O] turn: ";
    
    cin >> choice;
    
    switch (choice) {
        case 1:
            row = 0; col = 0;
            break;
        case 2:
            row = 0; col = 1;
            break;
        case 3:
            row = 0; col = 2;
            break;
        case 4:
            row = 1; col = 0;
            break;
        case 5:
            row = 1; col = 1;
            break;
        case 6:
            row = 1; col = 2;
            break;
        case 7:
            row = 2; col = 0;
            break;
        case 8:
            row = 2; col = 1;
            break;
        case 9:
            row = 2; col = 2;
            break;
            
        default:
            cout<<"Invalid Choice!!!"<<endl;
            break;
    }
    if(turn == 'X' && board[row][col] != 'X' && board[row][col]!= 'O') { //to prevent over writing
        board[row][col] = 'X';
        turn = 'O';
    } else if(turn == 'O' && board[row][col] != 'X' && board[row][col]!= 'O') { //to prevent over writing
        board[row][col] = 'O';
        turn = 'X';
    } else {
        cout<<"\n\tBOX already filled! Please try again...";
        player_turn();
    }
    display_board();
}

bool game_over() {
    //check win
    for(int i = 0; i < 3 ; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) //vertical and horizontals
    return false;
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) //diagonals
    return false;
    
    //if there is any box not filled
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j]!='O')
                return true;
    //draw
    draw = true;
    return false;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...

    while (game_over()) {
        display_board();
        player_turn();
        game_over();
    }
    
    if(turn == 'X' && draw == false)
        cout<<"Player2 [0] Wins!! Congratulations\n";
    else if(turn == 'O' && draw == false)
        cout << "Player1 [X] Wins!! Congratulations\n";
    else
        cout << "GAME DRAW!! \n";

    
}
