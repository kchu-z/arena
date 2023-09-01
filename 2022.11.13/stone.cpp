#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, br = 0;
    cin >> n;

    unordered_map <int, bool> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (!m[num]) {
            br++;
            m[num] = true;
        }
    }

    cout << br;

    return 0;

}
