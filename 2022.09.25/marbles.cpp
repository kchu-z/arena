#include <bits/stdc++.h>
using namespace std;

string v;

void exec() {
    string s;
    for (int i = 0; i < v.size(); i++) {
        if ((i + 1 == v.size() && v[i] != v[i + 1]) && (i == 0 && v[i] != v[i - 1])) s.push_back(v[i]);
    }
    cout << s << endl;
    v = s;
}

bool check() {
    for (int i = 0; i < v.size(); i++) {
        if ((i + 1 == v.size() || v[i] != v[i + 1]) && (i != 0 && v[i] == v[i - 1])) return false;
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;

    while ((int) v.size() > 2 && (!check())) exec();

    if (v.size() == 0) cout << "EMPTY";
    else cout << v;

    return 0;

}

