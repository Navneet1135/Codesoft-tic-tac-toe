#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>> &board) {
    cout << "\n";
    for (const auto &row : board) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (const auto &cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        // Initialize the game board
        vector<vector<char>> board(3, vector<char>(3, '-'));
        char currentPlayer = 'X';
        bool gameWon = false;

        cout << "Welcome to Tic Tac Toe!\n";
        displayBoard(board);

        while (true) {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column: 0 1 2): ";
            cin >> row >> col;

            // Validate input
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            // Update board
            board[row][col] = currentPlayer;
            displayBoard(board);

            // Check for win or draw
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
                break;
            }

            if (checkDraw(board)) {
                cout << "It's a draw!\n";
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";
    return 0;
}