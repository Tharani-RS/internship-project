#include <iostream>
using namespace std;

char board[3][3];

// Initialize Board
void initializeBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Display Board
void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2)
                cout << " | ";
        }
        cout << "\n";
        if(i < 2)
            cout << "---|---|---\n";
    }
    cout << "\n";
}

// Check Winner
bool checkWinner() {
    // Rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

// Check Draw
bool checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Make Move
bool makeMove(int position, char player) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if(position < 1 || position > 9)
        return false;

    if(board[row][col] == 'X' ||
       board[row][col] == 'O')
        return false;

    board[row][col] = player;
    return true;
}

int main() {
    char replay;

    do {
        initializeBoard();

        char currentPlayer = 'X';
        int position;

        while(true) {
            displayBoard();

            cout << "Player " << currentPlayer
                 << ", enter position (1-9): ";
            cin >> position;

            if(!makeMove(position, currentPlayer)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if(checkWinner()) {
                displayBoard();
                cout << "Player "
                     << currentPlayer
                     << " Wins!\n";
                break;
            }

            if(checkDraw()) {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            currentPlayer =
                (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> replay;

    } while(replay == 'Y' || replay == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}
