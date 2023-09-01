#include <bits/stdc++.h>
using namespace std;

bool isOpening(char c) {
    return c == '(' || c == '<' || c == '[' || c == '{';
}

char getOpposite(char c) {
    if (c == '(') return ')';
    if (c == '<') return '>';
    if (c == '[') return ']';
    if (c == '{') return '}';
}

int main() {

    stack <char> s;
    char c;

    while (cin >> c) {
        if (c == '|') {
            if (!s.empty() && s.top() == '|') s.pop();
            else s.push(c);
        } else if (isOpening(c)) s.push(c);
        else {
            if (!s.empty() && getOpposite(s.top()) == c) {
                s.pop();
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
    return 0;

}
