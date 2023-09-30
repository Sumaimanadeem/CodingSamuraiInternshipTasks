#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string playerNames[2];
int currentPlayer = 0; 
bool isGameOver = false;

// Function to display the game board
void displayBoard() {
    system("cls");
    cout << "\n\tTic Tac Toe Game\n\n";
    cout << "Player " << playerNames[0] << " (X)  -  Player " << playerNames[1] << " (O)" << endl << endl;
    
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}

// Function to check for a win
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns for a win
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] ||
            board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer + 1; 
        }
    }
    
    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer + 1; 
    }
    
    // Check for a draw
    bool isBoardFull = true;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                isBoardFull = false;
                break;
            }
        }
    }
    if (isBoardFull) {
        return 0; // Draw
    }
    
    return -1; // Game in progress
}

// Function to handle player's move
void makeMove() {
    int choice;
    cout << "Player " << playerNames[currentPlayer] << ", enter a number: ";
    cin >> choice;

    // Convert choice to board coordinates
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = (currentPlayer == 0) ? 'X' : 'O';
        int result = checkWin();
        if (result == -1) {
            currentPlayer = 1 - currentPlayer; 
        }
    } else {
        cout << "Invalid move. Please try again." << endl;
    }
}

int main() {
    cout << "Enter the name for player 1: ";
    cin >> playerNames[0];
    cout << "Enter the name for player 2: ";
    cin >> playerNames[1];

    while (!isGameOver) {
        displayBoard();
        makeMove();
        int result = checkWin();
        if (result == 1 || result == 2) {
            displayBoard();
            cout << "CONGRATULATIONS! " << playerNames[result - 1] << " has won the game!" << endl;
            isGameOver = true;
        } else if (result == 0) {
            displayBoard();
            cout << "It's a draw!" << endl;
            isGameOver = true;
        }
    }

    return 0;
}
