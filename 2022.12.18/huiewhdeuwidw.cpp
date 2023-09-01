#include <bits/stdc++.h>
using namespace std;

int main() {

    int mehur = 0;
    char c;
    stack <char> s;

    while (cin >> c) {
        if (c == 'O') {
            if (s.empty() || s.top() != 'L') {
                s.push('O');
                mehur++;
            }
        } else if (c == 'T') {
            while (!s.empty() && s.top() == 'O') {
                s.pop();
                mehur--;
            }

            s.push('T');
        } else s.push('L');
    }

    cout << s.size() << ' ' << mehur << endl;
    return 0;

}
