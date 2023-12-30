#include<iostream>

using namespace std;

char squair[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkWin() {
    // Rows
    if (squair[1] == squair[2] && squair[2] == squair[3]) return 1;
    else if (squair[4] == squair[5] && squair[5] == squair[6]) return 1;
    else if (squair[7] == squair[8] && squair[8] == squair[9]) return 1;

    // Columns
    else if (squair[1] == squair[4] && squair[4] == squair[7]) return 1;
    else if (squair[2] == squair[5] && squair[5] == squair[8]) return 1;
    else if (squair[3] == squair[6] && squair[6] == squair[9]) return 1;

    // Diagonals
    else if (squair[1] == squair[5] && squair[5] == squair[9]) return 1;
    else if (squair[3] == squair[5] && squair[5] == squair[7]) return 1;

    // Check if the game is still ongoing
    else if (squair[1] != '1' && squair[2] != '2' && squair[3] != '3' &&
             squair[4] != '4' && squair[5] != '5' && squair[6] != '6' &&
             squair[7] != '7' && squair[8] != '8' && squair[9] != '9') return 0;

    // Game is still ongoing
    else return -1;
}

void board() {
    system("cls");
    cout << "\n\nTic Tac Toe Game \n\n";
    cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
    cout << "  |   |    " << endl;
    cout << "" << squair[1] << " | " << squair[2] << " | " << squair[3] << endl;
    cout << "__|___|___" << endl;
    cout << "  |   |    " << endl;
    cout << "" << squair[4] << " | " << squair[5] << " | " << squair[6] << endl;
    cout << "__|___|___" << endl;
    cout << "  |   |    " << endl;
    cout << "" << squair[7] << " | " << squair[8] << " | " << squair[9] << endl;
  
}

char playAgain() {
    char choice;
    cout << "Do you want to play another game? (y/n): ";
    cin >> choice;
    return choice;
}

int main() {
    char playAnotherGame;
    do {
        for (int i = 1; i <= 9; ++i) {
            squair[i] = '0' + i;
        }

        int player = 1, i, choice;
        char mark;
        do {
            board();
            player = (player % 2) ? 1 : 2;
            cout << "Player " << player << ", Enter the Number: ";
            cin >> choice;
            mark = (player == 1) ? 'X' : 'O';
            if (choice >= 1 && choice <= 9 && squair[choice] == '0' + choice) {
                squair[choice] = mark;
            } else {
                cout << "Invalid move. Try again." << endl;
                player--;
                cin.ignore();
                cin.get();
            }
            i = checkWin();
            player++;
        } while (i == -1);
        board();
        if (i == 1) {
            cout << "\aCongratulations! Player " << --player << " wins!" << endl;
        } else {
            cout << "Game Draw!" << endl;
        }
        playAnotherGame = playAgain();
    } while (playAnotherGame == 'y' || playAnotherGame == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}

