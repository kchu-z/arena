#include <bits/stdc++.h>
using namespace std;

vector <long long> d(long long a) {
    vector <long long> v;
    for (long long i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (i * i == a) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(a / i);
            }
        }
    }

    return v;
}

long long d(vector <long long>& a, vector <long long>& b) {
    vector <long long> v;
    long long br = 0;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) v.push_back(a[i] * b[j]);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (i + 1 == v.size() || v[i] != v[i + 1]) br++;
    }

    return br;
}

int main() {

    long long a, b, br = 0;
    cin >> a >> b;

    vector <long long> A = d(a), B = d(b);
    long long AB = d(A, B);

    for (long long x : A) {
        long long dx = d(x).size();
        for (long long y : B) {
            long long dy = d(y).size();
            if (AB % (dx + dy) == 0) br++;
        }
    }

    cout << br << endl;

    return 0;

}
