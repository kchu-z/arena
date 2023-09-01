#include <bits/stdc++.h>
using namespace std;

int arr[5][5];

bool check(int i, int j) {
    int br[2] = {};
    br[arr[i + 1][j]]++;
    br[arr[i][j + 1]]++;
    br[arr[i + 1][j + 1]]++;

    if (br[0] == 2 && br[1] == 2) {cout<<1;return true;}
    return false;
}

int exec(int row) {
    if (row == 5) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!check(i, j)) return 0;
            }
        }

        return 1;
    } else {
        int br = 0;

        for (int a = 0; a < 2; a++) {
            arr[row][0] = a;
            for (int b = 0; b < 2; b++) {
                arr[row][1] = b;
                for (int c = 0; c < 2; c++) {
                    arr[row][2] = c;
                    for (int d = 0; d < 2; d++) {
                        arr[row][3] = d;
                        for (int e = 0; e < 2; e++) {
                            arr[row][4] = e;
                            br += exec(row + 1);
                        }
                    }
                }
            }
        }

        return br;
    }
}

int main() {

    cout << exec(0);

    return 0;

}
