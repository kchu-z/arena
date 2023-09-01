#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> v;
int n, mx = 0;



int solve(int chain, pair <int, int> pos, int sum) {
    chain--;
    sum += v[pos.first][pos.second];

    if (chain == 0) {
        pos = {n - 1, n - 1};
        sum += v[pos.first][pos.second];

        mx = max(mx, sum);

        return 0;
    }

    if (pos.first == n - 1) {
        pos.second++;

        solve(chain, pos, sum);
        return 0;
    }

    if (pos.second == n - 1) {
        pos.first++;

        solve(chain, pos, sum);
        return 0;
    }

    pos.first++;
    solve(chain, pos, sum);

    pos.first--;
    pos.second++;

    solve(chain, pos, sum);

    return 0;
}

void flip() {
    vector <vector <int>> s(n, vector <int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[j][n - i - 1] = v[i][j];
        }
    }

    v = s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector <vector <int>> __v(n, vector <int> (n));
    v = __v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char s, __s;
            cin >> s >> __s;

            if (isdigit(s)) v[i][j] = s - '0';
            if (s == 'A') v[i][j] = 1;
            if (s == 'T') v[i][j] = 10;
            if (s == 'J') v[i][j] = 11;
            if (s == 'Q') v[i][j] = 12;
            if (s == 'K') v[i][j] = 13;
        }
    }

    int chain = 2 * (n - 1);
    pair <int, int> pos = {0, 0};

    flip();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //cout << v[i][j] << ' ';
        }

        //cout << endl;
    }

    solve(chain, pos, 0);

    cout << mx << endl;
    return 0;

}
/// 4 8S AD 3C AC 8C 4H QD QS 5D 9H KC 7H TC QC AS 2D
