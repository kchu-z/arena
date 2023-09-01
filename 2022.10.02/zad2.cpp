#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector <int> v, v2;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            v2.push_back(v[i] * v[j]);
        }
    }

    sort(v2.begin(), v2.end());
    int br = 0;

    for (int i = 0; i < v2.size(); i++) {
        if (i == n - 1 || v2[i] != v2[i + 1]) br++;
    }

    cout << br;

    return 0;

}
