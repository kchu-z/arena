#include <bits/stdc++.h>
using namespace std;

bool grid[24][24];

void shoot_horizontal(int x) {
    for (int y = 0; y < 24; y++) {
        grid[x][y] = 0;
    }
}

void shoot_vertical(int x) {
    for (int y = 0; y < 24; y++) {
        grid[y][x] = 0;
    }
}

void shoot_diagonal_1(int x, int y) {
    int pos_x = x, pos_y = y;

    while (pos_x != -1 && pos_y != -1) {
        grid[pos_x][pos_y] = 0;
        pos_x--;
        pos_y--;
    }

    pos_x = x;
    pos_y = y;

    while (pos_x != 24 && pos_y != 24) {
        grid[pos_x][pos_y] = 0;
        pos_x++;
        pos_y++;
    }
}

void shoot_diagonal_2(int x, int y) {
    int pos_x = x, pos_y = y;

    while (pos_x != -1 && pos_y != 24) {
        grid[pos_x][pos_y] = 0;
        pos_x--;
        pos_y++;
    }

    pos_x = x;
    pos_y = y;

    while (pos_x != 24 && pos_y != -1) {
        grid[pos_x][pos_y] = 0;
        pos_x++;
        pos_y--;
    }
}

int main() {

    int x, y;

    while (cin >> x >> y) grid[x][y] = 1;

    for (int x1 = 0; x1 < 24; x1++) for (int y1 = 0; y1 < 24; y1++)
    for (int x2 = 0; x2 < 24; x2++) for (int y2 = 0; y2 < 24; y2++) {
        int newGrid[24][24];

        for (int i = 0; i < 24; i++) for (int j = 0; j < 24; j++) newGrid[i][j] = grid[i][j];

        shoot_horizontal(x1);
        shoot_horizontal(x2);
        shoot_vertical(y1);
        shoot_vertical(y2);
        shoot_diagonal_1(x1, y1);
        shoot_diagonal_1(x2, y2);
        shoot_diagonal_2(x1, y1);
        shoot_diagonal_2(x2, y2);

        bool f = true;

        for (int i = 0; i < 24; i++) for (int j = 0; j < 24; j++) {
            if (grid[i][j] == 1) {
                f = false;
                break;
            }
        }

        if (f) {
            cout << x1 << ' ' << y1 << endl;
            cout << x2 << ' ' << y2 << endl << endl;
        }

        for (int i = 0; i < 24; i++) for (int j = 0; j < 24; j++) grid[i][j] = newGrid[i][j];
    }


    return 0;

}
/*
2 23
4 20
5 16
6 23
9 19
9 21
10 19
11 22
14 11
18 11
20 23
21 20
22 15
*/





/*
0 4 0 10
1 7
2 0 2 14
3 4 3 14
4 6
6 7
9 4 9 16
10 7
11 15
14 3
21 18
23 7
*/
