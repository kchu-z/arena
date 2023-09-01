#include <bits/stdc++.h>
using namespace std;

vector <int> d(int n) {
    vector <int> v;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n == i * i) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }

    sort(v.begin(), v.end());
    return v;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector <int> v = d(n), arr;

    for (int i = 0; i < q; i++) {
        cin >> arr[i];


    }

    for (int i : v) {
            if (i >= num) {
                cout << i << '\n';
                break;
            }
        }

    return 0;

}
