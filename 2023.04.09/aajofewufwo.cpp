#include <bits/stdc++.h>
using namespace std;

bool visited[200][200];
int n, m, br;

void dfs(int x, int y) {
    if (min(x, y) < 0 || x >= n || y >= m) return;
    if (visited[x][y]) return;
    visited[x][y] = 1;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> visited[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                br++;
                dfs(i, j);
            }
        }
    }

    cout << br << endl;
    return 0;

}


