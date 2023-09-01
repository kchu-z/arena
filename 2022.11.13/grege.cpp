#include <bits/stdc++.h>
using namespace std;

vector <int> d(int n) {
    vector <int> v;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }

    if (n != 1) v.push_back(n);

    return v;
}

int main() {

    int n, num;
    cin >> n;

    vector <int> v;

    for (int i = 0; i < n; i++) {
        cin >> num;
        vector <int> v2 = d(num);

        for (int i : v2) cout << i << ' ';
        cout << endl;

        for (int i : v2) v.push_back(i);
        sort(v.begin(), v.end());
    }

    cout << endl << endl << endl;
    for (int i : v) cout << i << ' ';
    cout << endl;

    int br = 0, p = 1;

    for (int i = 0; i < v.size(); i++) {
        br++;
        if (i + 1 == v.size() || v[i] != v[i + 1]) {
            p *= br + 1;
            br = 0;
        }
    }

    cout << p;

    return 0;

}
