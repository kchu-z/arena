#include <bits/stdc++.h>
#define endl '\n'
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

vector <int> d(vector <int>& a, vector <int>& b) {
    vector <int> v, s;

    for (int x : a) for (int y : b) {
        v.push_back(x * y);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (i + 1 == v.size() || v[i] != v[i + 1]) {
            s.push_back(v[i]);
        }
    }

    return s;
}

int main() {

    int n, num;
    cin >> n;
    vector <int> v, b;

    cin >> n;
    v = d(num);
    for (int i : v) cout << i << ' ';
    cout << endl;

    for (int i = 1; i < n; i++) {
        cin >> num;
        b = d(num);
        v = d(b, v);
        for (int i : v) cout << i << ' ';
        cout << endl;
    }

    cout << v.size() % 10;

    return 0;

}
