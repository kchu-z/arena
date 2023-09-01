#include <bits/stdc++.h>
using namespace std;

unordered_map <string, vector <string>> children;
unordered_map <string, string> parent;
unordered_map <string, int> dynasty;

int get_children(string s) {
    auto v = children[s];

    if (v.empty()) return 0;
    int generations = 0;

    int ds = dynasty[s];

    if (ds) return ds;

    for (string& child : children[s]) {
        generations = max(generations, 1 + get_children(child));
    }

    return dynasty[s] = generations;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    vector <string> parents;

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        string par = parent[b];

        if (par.size() && par != a) {
            cout << b << endl;
            return 0;
        }

        if (par == a) continue;

        if (children[a].empty()) parents.push_back(a);

        children[a].push_back(b);
        //cout << a << ' ' << b << endl;
        parent[b] = a;
    }

    int maxgen = 0;
    string maxgenname;

    for (auto p : parents) {
        string name = p;
        int generations = get_children(name);

        //cout << name << ' ' << generations << endl;

        if (maxgen < generations) {
            maxgen = generations;
            maxgenname = name;
        } else if (maxgen == generations) maxgenname = max(maxgenname, name);
    }

    cout << maxgenname << endl;
    return 0;

}
