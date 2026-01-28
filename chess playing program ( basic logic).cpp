#include <iostream>
using namespace std;

const int SIZE = 8;

// Board display function
void displayBoard(int px, int py, int cx, int cy) {
    cout << "\nChess Board:\n\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == px && j == py)
                cout << " P ";   // Player King
            else if (i == cx && j == cy)
                cout << " C ";   // Computer King
            else
                cout << " . ";
        }
        cout << endl;
    }
}

int main() {
    int playerX = 0, playerY = 0;
    int chaserX = 7, chaserY = 7;
    char move;

    cout << "=== BASIC CHESS PLAYING LOGIC (KING CHASE) ===\n";
    cout << "Controls: W (up), S (down), A (left), D (right)\n";

    while (true) {
        displayBoard(playerX, playerY, chaserX, chaserY);

        // Player Move
        cout << "\nEnter your move: ";
        cin >> move;

        if (move == 'W' || move == 'w') {
            if (playerX > 0) playerX--;
        }
        else if (move == 'S' || move == 's') {
            if (playerX < SIZE - 1) playerX++;
        }
        else if (move == 'A' || move == 'a') {
            if (playerY > 0) playerY--;
        }
        else if (move == 'D' || move == 'd') {
            if (playerY < SIZE - 1) playerY++;
        }
        else {
            cout << "Invalid move!\n";
            continue;
        }

        // Computer (Chaser) Logic
        if (chaserX < playerX) chaserX++;
        else if (chaserX > playerX) chaserX--;

        if (chaserY < playerY) chaserY++;
        else if (chaserY > playerY) chaserY--;

        // Catch condition
        if (playerX == chaserX && playerY == chaserY) {
            displayBoard(playerX, playerY, chaserX, chaserY);
            cout << "\nGame Over – You are caught!\n";
            break;
        }
    }

    return 0;
}
