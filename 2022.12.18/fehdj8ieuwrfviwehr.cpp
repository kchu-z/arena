#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, num;
    cin >> n;

    stack <int> s;

    for (int i = 0; i < n; i++) {
        cin >> t;

        if (t == 1) {
            cin >> num;
            if (s.empty()) s.push(num);
            else s.push(max(s.top(), num));
        } else s.pop();

        if (s.empty()) cout << "-1 ";
        else cout << s.top() << ' ';
    }

    return 0;

}
