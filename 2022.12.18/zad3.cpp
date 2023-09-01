#include <bits/stdc++.h>
#include <string>
using namespace std;

string s, a, b, c;
char og, op;

vector <pair <pair <string, string>, string> > ans;

int exec_op() {
    if (op == '+') return stoi(a) + stoi(b);
    return stoi(a) * stoi(b);
}

void check_b(int pos) {
    if (pos == b.size()) {
        string num = to_string(exec_op());

        if (c.size() == num.size()) {
            bool f = true;

            for (int i = 0; i < c.size(); i++) {
                if (isdigit(c[i]) && c[i] != num[i]) {
                    f = false;
                    break;
                }
            }

            if (f) {
                if (og == '+' || og == '*') ans.push_back({{a, b}, num});
                else ans.push_back({{num, b}, a});
            }
        }
    } else if (b[pos] == '?') {
        for (int i = 0; i < 10; i++) {
            if (pos == 0 && i == 0) continue;
            b[pos] = i + '0';
            check_b(pos + 1);
        }
        b[pos] = '?';
    } else check_b(pos + 1);
}

void check_a(int pos) {
    if (pos == a.size()) {
        check_b(0);
    } else if (a[pos] == '?') {
        for (int i = 0; i < 10; i++) {
            if (pos == 0 && i == 0) continue;
            a[pos] = i + '0';
            check_a(pos + 1);
        }
        a[pos] = '?';
    } else check_a(pos + 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, s, '=');
    cin >> c;

    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]) && s[i] != '?') {
            a = s.substr(0, i);
            b = s.substr(i + 1);
            og = s[i];
        }
    }

    if (og == '-') {
        swap(a, c);
        op = '+';
    } else if (og == '/') {
        swap(a, c);
        op = '*';
    } else op = og;

    //cout << a << op << b << '=' << c;

    check_a(0);
    sort(ans.begin(), ans.end());

    for (auto& i : ans) {
        cout << i.first.first << ' ' << i.first.second << ' ' << i.second << '\n';
    }

    return 0;

}
