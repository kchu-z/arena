#include <bits/stdc++.h>
using namespace std;

pair <int, int> distance(pair <int, int>& a, pair <int, int>& b) {
    return {b.first - a.first, b.second - a.second};
}

vector <pair <pair <int, int>, pair <int, int>>> v{{{-1, 0}, {-1, -1}}, {{-1, 0}, {-1, 1}}, {{-1, 0}, {1, 0}}, {{0, -1}, {-1, -1}}, {{0, -1}, {1, -1}}, {{0, -1}, {0, 1}}, {{0, 1}, {-1, 1}}, {{0, 1}, {1, 1}}, {{1, 0}, {1, -1}}, {{1, 0}, {1, 1}}};

int main() {

    int m, n;
    cin >> m >> n;

    int arr[202][202] = {{}}, check[15000] = {};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            check[arr[i][j]]++;
        }
    }

    if (check[0] > 2) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i < 15000; i++) {
        if (check[i] != 3) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 0) continue;
            bool f = false;

            for (auto& k : v) {
                pair <int, int> pos1 = {i + k.first.first, j + k.first.second}, pos2 = {i + k.second.first, j + k.second.second};

                if (arr[pos1.first][pos1.second] == arr[pos2.first][pos2.second] && arr[pos1.first][pos1.second] == arr[i][j]) f = true;
            }

            if (!f) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;

}
/*
4 8
1 2 2 2 6 7 7 9
1 4 4 3 6 7 8 9
1 0 4 3 6 8 8 9
10 10 10 3 0 5 5 5
*/
