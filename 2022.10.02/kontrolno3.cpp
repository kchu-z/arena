#include <bits/stdc++.h>
using namespace std;

vector <long long> d(long long n) {
    vector <long long> v;

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

    return v;
}

vector <long long> d(vector <long long>& a, vector <long long>& b) {
    vector <long long> v, s;

    for (long long x : a) {
        for (long long y : b) {
            s.push_back(x * y);
        }
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
        if (i + 1 == s.size() || s[i] != s[i + 1]) {
            v.push_back(s[i]);
        }
    }

    return v;
}

int main() {

    long long n, num;
    cin >> n >> num;
    vector <long long> v;
    v = d(num);
    vector <long long> s;

    for (long long i = 1; i < n; i++) {
        cin >> num;
        s = d(num);
        v = d(v, s);
    }

    for (long long x : v) cout << x << ' ';


    return 0;

}
