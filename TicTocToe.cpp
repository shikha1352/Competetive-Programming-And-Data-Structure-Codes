#include <bits/stdc++.h>
using namespace std;

const char PLAYER = 'X';
const char AI = 'O';
const char EMPTY = ' ';

void displayBoard(const vector<vector<char>> &b) {
    for (int i = 0; i < 3; i++) {
        cout << " " << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
}

char checkWinner(const vector<vector<char>> &b) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0] != EMPTY && b[i][0] == b[i][1] && b[i][1] == b[i][2]) return b[i][0];
        if (b[0][i] != EMPTY && b[0][i] == b[1][i] && b[1][i] == b[2][i]) return b[0][i];
    }
    if (b[0][0] != EMPTY && b[0][0] == b[1][1] && b[1][1] == b[2][2]) return b[0][0];
    if (b[0][2] != EMPTY && b[0][2] == b[1][1] && b[1][1] == b[2][0]) return b[0][2];

    for (size_t i = 0; i < b.size(); i++)
        for (size_t j = 0; j < b[i].size(); j++)
            if (b[i][j] == EMPTY) return EMPTY;

    return 'D'; 
}

pair<int, int> bestMove(vector<vector<char>> &b) {
    // 1. Try to win
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] == EMPTY) {
                b[i][j] = AI;
                if (checkWinner(b) == AI) { b[i][j] = EMPTY; return make_pair(i, j); }
                b[i][j] = EMPTY;
            }

    // 2. Block opponent
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] == EMPTY) {
                b[i][j] = PLAYER;
                if (checkWinner(b) == PLAYER) { b[i][j] = EMPTY; return make_pair(i, j); }
                b[i][j] = EMPTY;
            }

    // 3. Center
    if (b[1][1] == EMPTY) return make_pair(1, 1);

    // 4. Corner
    vector<pair<int,int>> corners;
    corners.push_back(make_pair(0,0));
    corners.push_back(make_pair(0,2));
    corners.push_back(make_pair(2,0));
    corners.push_back(make_pair(2,2));
    for (size_t k = 0; k < corners.size(); k++)
        if (b[corners[k].first][corners[k].second] == EMPTY)
            return corners[k];

    // 5. Side
    vector<pair<int,int>> sides;
    sides.push_back(make_pair(0,1));
    sides.push_back(make_pair(1,0));
    sides.push_back(make_pair(1,2));
    sides.push_back(make_pair(2,1));
    for (size_t k = 0; k < sides.size(); k++)
        if (b[sides[k].first][sides[k].second] == EMPTY)
            return sides[k];

    return make_pair(-1, -1);
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, EMPTY));

    while (true) {
        displayBoard(board);
        int row, col;
        cout << "Enter your move (row col 0-2): ";
        if (!(cin >> row >> col) || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = PLAYER;
        char res = checkWinner(board);
        if (res == PLAYER) { displayBoard(board); cout << "You win!\n"; break; }
        if (res == 'D') { displayBoard(board); cout << "Draw!\n"; break; }

        pair<int, int> aiPos = bestMove(board);
        int aiR = aiPos.first;
        int aiC = aiPos.second;
        board[aiR][aiC] = AI;
        cout << "AI played: " << aiR << " " << aiC << "\n";
        res = checkWinner(board);
        if (res == AI) { displayBoard(board); cout << "AI wins!\n"; break; }
        if (res == 'D') { displayBoard(board); cout << "Draw!\n"; break; }
    }
}

