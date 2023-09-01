#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, current = 1, total = 0;
    cin >> n;
    char s;

    for (int i = 0; i < n - 1; i++) {
        cin >> s;

        if (s == '<') {
            for (int i = total + current; i > total; i--) {
                cout << i << ' ';
            }

            total += current;
            current = 1;
        } else current++;
    }

    for (int i = total + current; i > total; i--) {
        cout << i << ' ';
    }

    return 0;

}
