#include <iostream>
#include <limits>
using namespace std;

char brd[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char turn = 'X';  // Player always 'X', AI always 'O'
bool drow = false;

void bord() {
    system("cls"); // Windows e kaj korbe, Linux/Mac e na
    cout << "\n\n\t This is  T I C   T A C    T O E    Game!" << endl;
    cout << "\n\tPlayer1 [X] (You)";
    cout << "\n\tPlayer2 [O] (AI)\n\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t  " << brd[0][0] << "   |  " << brd[0][1] << "  |  " << brd[0][2] << "  \n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t _____|_____|_____\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t  " << brd[1][0] << "   |  " << brd[1][1] << "  |  " << brd[1][2] << "  \n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t _____|_____|_____\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t  " << brd[2][0] << "   |  " << brd[2][1] << "  |  " << brd[2][2] << "  \n";
    cout << "\t\t      |     |     \n\n";
}

bool movesLeft(char b[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] != 'X' && b[i][j] != 'O')
                return true;
    return false;
}

int evaluate(char b[3][3]) {
    // Check rows for win
    for (int row = 0; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == 'X')
                return +10;
            else if (b[row][0] == 'O')
                return -10;
        }
    }

    // Check columns for win
    for (int col = 0; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == 'X')
                return +10;
            else if (b[0][col] == 'O')
                return -10;
        }
    }

    // Check diagonals for win
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == 'X')
            return +10;
        else if (b[0][0] == 'O')
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == 'X')
            return +10;
        else if (b[0][2] == 'O')
            return -10;
    }

    // No one won
    return 0;
}

int minimax(char b[3][3], int depth, bool isMax) {
    int score = evaluate(b);

    if (score == 10)
        return score - depth;  // Sooner win is better
    if (score == -10)
        return score + depth;  // Sooner lose is worse

    if (!movesLeft(b))
        return 0;  // Draw

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] != 'X' && b[i][j] != 'O') {
                    char backup = b[i][j];
                    b[i][j] = 'X';
                    best = max(best, minimax(b, depth + 1, false));
                    b[i][j] = backup;
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] != 'X' && b[i][j] != 'O') {
                    char backup = b[i][j];
                    b[i][j] = 'O';
                    best = min(best, minimax(b, depth + 1, true));
                    b[i][j] = backup;
                }
            }
        }
        return best;
    }
}

pair<int, int> findBestMove(char b[3][3]) {
    int bestVal = 1000;
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] != 'X' && b[i][j] != 'O') {
                char backup = b[i][j];
                b[i][j] = 'O';
                int moveVal = minimax(b, 0, true);
                b[i][j] = backup;

                if (moveVal < bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void player_turn() {
    if (turn == 'X') {
        int choice;
        while (true) {
            cout << "Your turn [X]. Enter location (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9) {
                cout << "Invalid input! Try again.\n";
                continue;
            }

            int r = (choice - 1) / 3;
            int c = (choice - 1) % 3;

            if (brd[r][c] != 'X' && brd[r][c] != 'O') {
                brd[r][c] = 'X';
                turn = 'O';
                break;
            }
            else {
                cout << "Box already filled! Try again.\n";
            }
        }
    }
    else {
        cout << "AI's turn [O]. AI is thinking...\n";
        pair<int, int> bestMove = findBestMove(brd);
        brd[bestMove.first][bestMove.second] = 'O';
        turn = 'X';
    }
    bord();
}

bool gameover() {
    int score = evaluate(brd);

    if (score == 10 || score == -10) 
        return false; // someone won

    if (!movesLeft(brd)) {
        drow = true;
        return false; // draw
    }

    return true; // game continues
}

int main() {
    bord();
    while (gameover()) {
        player_turn();
    }

    if (drow) {
        cout << "Game Draw!!\n";
    }
    else {
        if (turn == 'X')  // last move by 'O'
            cout << "AI [O] wins! Better luck next time.\n";
        else
            cout << "You [X] win! Congratulations!\n";
    }
    return 0;
}
