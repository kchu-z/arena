#include <bits/stdc++.h>
using namespace std;

vector <int> d(int n) {
    vector <int> v;

    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        if (i * i == n) v.push_back(i);
        else {
            v.push_back(i);
            v.push_back(n / i);
        }
    }

    return v;
}

vector <int> d(vector <int>& a, vector <int>& b) {
    vector <int> v, s;

    for (int x : a) {
        for (int y : b) {
            v.push_back(x * y);
        }
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
    vector <int> v, s;

    cin >> num;
    v = d(num);

    for (int i = 1; i < n; i++) {
        cin >> num;
        s = d(num);
        v = d(v, s);
    }

    cout << (int) v.size() % 10;

    return 0;

}
