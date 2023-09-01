#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001], n, m;
bool used[1001][1001];
bool check(int x, int y) {
    if (1 <= x && x <= n && 1 <= y && y <= m && !used[x][y]) return 1;
    return 0;
}
void dfs(int x, int y) {
    used[x][y] = true;
    if (check(x - 1, y) && arr[x][y] == arr[x - 1][y]) dfs(x - 1, y);
    if (check(x + 1, y) && arr[x][y] == arr[x + 1][y]) dfs(x + 1, y);
    if (check(x, y - 1) && arr[x][y] == arr[x][y - 1]) dfs(x, y - 1);
    if (check(x, y + 1) && arr[x][y] == arr[x][y + 1]) dfs(x, y + 1);
}
int main() {
    int br = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (used[i][j]) continue;
            br++;
            dfs(i, j);
        }
    }
    cout << br << endl;
    return 0;

}
