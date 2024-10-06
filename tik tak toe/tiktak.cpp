#include <iostream>
#include <string>
using namespace std;

void display();
void playerMove(int player);
void playerSelection();
void checkResult();

string name1;
string name2;
int n, k;
char array[3][3] = { {'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'} };

void display() {
    char c = 221;
    char d = 205;
    cout << "\n        " << d << d << d << d << d << d << d << d << d << d << endl;
    for (int i = 0; i < 3; i++) {
        cout << "        " << c;
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << " " << c;
        }
        cout << endl;
    }
    cout << "        " << d << d << d << d << d << d << d << d << d << d;
    cout << endl << "\n\n";
}

void playerMove(int player) {
    char symbol = player == 1 ? 'x' : 'o';
    string playerName = player == 1 ? name1 : name2;
    cout << endl << "-----PLAYER " << player << "----- (" << playerName << ")\n";

    do {
        cout << "\nChoose Row (0, 1, 2): ";
        cin >> n;
        cout << "Choose Column (0, 1, 2): ";
        cin >> k;

        if (n < 0 || n > 2 || k < 0 || k > 2 || array[n][k] != '*') {
            cout << "Invalid move. Try again.\n";
        }
    } while (n < 0 || n > 2 || k < 0 || k > 2 || array[n][k] != '*');

    array[n][k] = symbol;
    display();
    checkResult();
}

void playerSelection() {
    for (int i = 0; i < 9; i++) {
        playerMove(i % 2 == 0 ? 1 : 2);
    }
}

void checkResult() {
    for (int i = 0; i < 3; i++) {
        if (array[i][0] == array[i][1] && array[i][1] == array[i][2] && array[i][0] != '*') {
            cout << "____| " << (array[i][0] == 'x' ? name1 : name2) << " WINS |____\n";
            exit(0);
        }
        if (array[0][i] == array[1][i] && array[1][i] == array[2][i] && array[0][i] != '*') {
            cout << "____| " << (array[0][i] == 'x' ? name1 : name2) << " WINS |____\n";
            exit(0);
        }
    }
    if (array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[0][0] != '*') {
        cout << "____| " << (array[0][0] == 'x' ? name1 : name2) << " WINS |____\n";
        exit(0);
    }
    if (array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] != '*') {
        cout << "____| " << (array[0][2] == 'x' ? name1 : name2) << " WINS |____\n";
        exit(0);
    }
}

int main() {
    cout << " PLAYER 1 ENTER YOUR NAME: ";
    cin >> name1;
    cout << "\n PLAYER 2 ENTER YOUR NAME: ";
    cin >> name2;
    cout << endl;
    display();
    playerSelection();
    cout << "It's a draw!";
    return 0;
}
