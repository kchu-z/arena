#include <bits/stdc++.h>
using namespace std;

bool visited[1000][1000];
bool is_patient[1000][1000];
int n, m;
vector <pair <int, int>> q;



int main() {

    cin >> n >> m;

    pair <int, int> end_square;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == 'x') visited[i][j] = 1;
            else if (c == 'S') {
                visited[i][j] = 1;
                q.push_back({i, j});
            } else if (c == 'T') {
                end_square = {i, j};
            } else if (c == '+') is_patient[i][j] = 1;

        }
    }

    while (!q.empty()) {
        auto pos = q.front();

        push(pos.first - 1, pos.second - 1, pos.first, pos.second);
        push(pos.first + 1, pos.second - 1, pos.first, pos.second);
        push(pos.first - 1, pos.second + 1, pos.first, pos.second);
        push(pos.first + 1, pos.second + 1, pos.first, pos.second);

        q.pop();
    }

    auto ans = patients[end_square.first][end_square.second];

    cout << ans.first << ' ' << ans.second << endl;
    return 0;

}

