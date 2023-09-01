#include <bits/stdc++.h>
#define endl '\n'
#define _max 10000000
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n;
    vector <bool> v(_max + 1, true);
    vector <int> arr(_max + 1);

    for (int i = 2; i * i <= _max; i++) {
        if (v[i]) {
            for (int j = 2 * i; j <= _max; j += i) {
                v[j] = false;
            }
        }
    }

    for (int i = 2; i <= _max; i++) {
        arr[i] = arr[i - 1] + (int) v[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }

    return 0;

}
