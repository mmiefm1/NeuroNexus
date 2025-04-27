#include <iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3]) {
    // Check if the board is full and there's no winner
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;
    char playAgain;

    do {
        cout << "Tic-Tac-Toe Game\n";
        printBoard(board);

        while (!gameOver) {
            cout << "Player " << currentPlayer << ", enter your move (row and column from 1 to 3): ";
            cin >> row >> col;
            row--; col--; // Adjust for 0-based index

            // Check if the cell is empty
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer; // Make the move
                printBoard(board); // Display the updated board after each move

                if (checkWin(board, currentPlayer)) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (checkDraw(board)) {
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
                }
            } else {
                cout << "Cell is already occupied. Try again!" << endl;
            }
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y') {
            // Reset the game board for a new game
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
                }
            }
            currentPlayer = 'X'; // Reset starting player
            gameOver = false; // Reset game over status
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
