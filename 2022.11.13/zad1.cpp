#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    int br = 0;

    for (int i = 0; i < a.size() - b.size() + 1; i++) {
        string n = a.substr(i, b.size());

        if (n == b) {
            br++;
            cout << i << ' ';
        }
    }

    cout << endl << br << endl;

    return 0;

}
