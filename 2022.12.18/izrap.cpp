#include <bits/stdc++.h>
using namespace std;

void shift(vector <long long>& v) {
    long long temp = v.front();

    for (int i = 0; i < v.size() - 1; i++) v[i] = v[i + 1];
    v[v.size() - 1] = temp;
}

int main() {

    long long n = 3, mx = 0;
    vector <long long> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        mx = max(mx, max(v[0] * v[1] + v[2], v[0] + v[1] * v[2]));
        shift(v);
    }

    cout << mx << endl;
    return 0;

}
