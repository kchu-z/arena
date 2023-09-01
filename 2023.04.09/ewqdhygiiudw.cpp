#include <bits/stdc++.h>
using namespace std;

string str, v[50];
int n, m;

bool check(int x, int y) {
    return 0 <= min(x, y) && x < n && y < m;
}

bool dfs(int x, int y, int k) {
    if (k == str.size()) return true;
    if (!check(x, y)) return false;
    if (v[x][y] != str[k]) return false;

    return max(max(dfs(x - 1, y, k + 1), dfs(x + 1, y, k + 1)), max(dfs(x, y - 1, k + 1), dfs(x, y + 1, k + 1)));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> str;
        bool f = false;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (dfs(x, y, 0)) {
                    f = true;
                    break;
                }
            }

            if (f) break;
        }

        if (f) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;

}
/**

5 6
glmnta
csoikf
dgotzf
hcnats
oemcpw
7
nato
god
meh
cat
catod
gg
stanchoemnogogotin

*/
