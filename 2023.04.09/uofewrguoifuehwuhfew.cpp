#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000][1000];

bool check(int x, int y) {
    bool first = 0 <= x && 0 <= y;
    bool second = x < n && y < n;
    bool third = false;

    if (first && second) {
        third = a[x][y] == 0;
    }

    return third;
}

void dfs(int x, int y) {
    if (!check(x, y)) return;
    a[x][y] = 1;

    cout << x << ' ' << y << endl;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            dfs(x + i, y + j);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char s;
            cin >> s;

            if (s == '@') {
                a[i][j] = 1;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (check(i + x, j + y)) {
                            //br++;
                            cout << "YES";
                            a[i + x][j + y] = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j]) {
                br++;
                dfs(i, j);
            }
        }
    }

    cout << br << endl;
    return 0;

}
