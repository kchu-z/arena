#include <bits/stdc++.h>
using namespace std;

int n, k;

vector <int> update(vector <int>& bits, int x, int delta) {
    for (int i = 0; i < 31; i++) {
        bits[i] += delta * (x % 2);

        x /= 2;
    }

    return bits;
}

bool check(vector <int>& bits, int x) {
    int sum = 0, pr = 1;

    for (int i = 30; i >= 0; i--) {
        sum += ((bool) bits[i]) * pr;
        pr *= 2;
    }

    return (sum | x) < k;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int br = 0;
    cin >> n >> k;
    vector <int> v(n), bits(31);

    for (int i = 0; i < n; i++) cin >> v[i];

    int j = -1;

    for (int i = 0; i < n; i++) {
        while (j + 1 < n && check(bits, v[j + 1])) {
            update(bits, v[j + 1], 1);
            j++;
        }

        cout << i << ' ' << j << endl;


        if (i <= j) update(bits, v[i], -1);
        else j = i;
    }

    cout << br << endl;
    return 0;

}
