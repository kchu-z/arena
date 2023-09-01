#include <bits/stdc++.h>
using namespace std;

string s;

bool is_opening(char s) {
    return s == '(' || s == '{' || s == '[';
}

bool is_closing(char s) {
    return !is_opening(s);
}

bool is_matching(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int f(int l, int r) {
    if (l > r) return 0;

    if (is_closing(s[l])) return 1 + f(l + 1, r);
    if (is_closing(s[r])) return 1 + f(l, r - 1);

    if (is_matching(s[l], s[r])) return f(l + 1, r - 1);

    vector <int> L, R:

    for (int i = l; i <= r; i++) {
        if (is_matching(s[l], s[i])) L.push_back(i);
        if (is_matching(s[i], s[r])) R.push_back(i);
    }

    if (L.empty() && R.empty()) return 2 + f(l + 1, r - 1);
    if (L.empty()) return 1 + f(l + 1, r);
    if (R.empty()) return 1 + f(l, r - 1);

    for (int right : R) {

    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    cout << f(l, r);
    return 0;

}
