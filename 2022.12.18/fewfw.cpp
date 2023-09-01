#include <bits/stdc++.h>
using namespace std;

int br, br1;

vector <vector <int>> edges(10000);
vector <bool> been(10000);

unordered_map <string, int> names;

int get_number(string s) {
    if (names.find(s) != names.end()) return names[s];
    names[s] = br;
    br++;

    return names[s];
}

void dfs(int num) {
    if (been[num]) return;
    been[num] = 1;
    br1++;

    for (int i : edges[num]) dfs(i);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;

    while (cin >> a) {
        if (cin >> b) {
            int c = get_number(a), d = get_number(b);
            edges[c].push_back(d);
            edges[d].push_back(c);

            continue;
        }

        dfs(get_number(a));
    }

    cout << br1 - 1 << endl;
    return 0;

}
