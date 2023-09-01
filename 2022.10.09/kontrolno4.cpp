#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {

    int n, a, b;
    cin >> n >> a >> b;
    vector <int> v(n * n + 1), s, arr[8];

    for (int i = 2; i <= n * n; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= n * n; j += i) {
                v[j]++;
            }
        }
    }

    for (int i = 1; i <= n * n; i++) {
        arr[v[i]].push_back(i);
    }

    for (int i = 0; i < 8; i++) {
        for (int x : arr[i]) {
            s.push_back(x);
        }
    }

    cout << s[(a - 1) * n + b - 1];

    return 0;

}
