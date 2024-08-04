#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
    char Playing_zone[3][3];
    string player1, player2;
    int row, column;
    char token;
    bool tie;

public:
    TicTacToe();
    void displayBoard();
    void getPlayersNames();
    void makeMove();
    bool checkWinner();
    void play();
};

TicTacToe::TicTacToe() : token('X'), tie(false) {
    char initial = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Playing_zone[i][j] = initial++;
        }
    }
}

void TicTacToe::displayBoard() {
    cout << "    |    |    " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << " " << Playing_zone[i][0] << "  | " << Playing_zone[i][1] << "  | " << Playing_zone[i][2] << endl;
        if (i < 2) {
            cout << "____|____|____" << endl;
            cout << "    |    |    " << endl;
        }
    }
    cout << "    |    |    " << endl;
}

void TicTacToe::getPlayersNames() {
    cout << "Enter the name of 1st player: ";
    getline(cin, player1);
    cout << "Enter the name of 2nd player: ";
    getline(cin, player2);
    cout << player1 << " will go first." << endl;
}

void TicTacToe::makeMove() {
    int digit;
    bool validMove = false;

    while (!validMove) {
        if (token == 'X') {
            cout << player1 << ", please enter a number (1-9): ";
        } else {
            cout << player2 << ", please enter a number (1-9): ";
        }
        cin >> digit;

        switch (digit) {
            case 1: row = 0; column = 0; break;
            case 2: row = 0; column = 1; break;
            case 3: row = 0; column = 2; break;
            case 4: row = 1; column = 0; break;
            case 5: row = 1; column = 1; break;
            case 6: row = 1; column = 2; break;
            case 7: row = 2; column = 0; break;
            case 8: row = 2; column = 1; break;
            case 9: row = 2; column = 2; break;
            default:
                cout << "Invalid input! Please enter a number between 1 and 9." << endl;
                continue;
        }

        if (Playing_zone[row][column] != 'X' && Playing_zone[row][column] != 'O') {
            Playing_zone[row][column] = token;
            validMove = true;
            token = (token == 'X') ? 'O' : 'X';
        } else {
            cout << "The cell is already occupied. Please choose another cell." << endl;
        }
    }
}

bool TicTacToe::checkWinner() {
    for (int i = 0; i < 3; ++i) {
        if ((Playing_zone[i][0] == Playing_zone[i][1] && Playing_zone[i][0] == Playing_zone[i][2]) ||
            (Playing_zone[0][i] == Playing_zone[1][i] && Playing_zone[0][i] == Playing_zone[2][i])) {
            return true;
        }
    }

    if ((Playing_zone[0][0] == Playing_zone[1][1] && Playing_zone[0][0] == Playing_zone[2][2]) ||
        (Playing_zone[0][2] == Playing_zone[1][1] && Playing_zone[0][2] == Playing_zone[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (Playing_zone[i][j] != 'X' && Playing_zone[i][j] != 'O') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

void TicTacToe::play() {
    getPlayersNames();
    while (!checkWinner() && !tie) {
        displayBoard();
        makeMove();
    }

    displayBoard();

    if (tie) {
        cout << "It's a draw!" << endl;
    } else {
        if (token == 'O') {
            cout << "The winner is " << player1 << "!" << endl;
        } else {
            cout << "The winner is " << player2 << "!" << endl;
        }
    }
}

int main() {
    cout << "====================================================================" << endl;
    cout << "                          TicTacToe game" << endl;
    cout << "====================================================================" << endl << endl;

    TicTacToe game;
    game.play();

    return 0;
}
