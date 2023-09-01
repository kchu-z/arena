#include <bits/stdc++.h>
using namespace std;

vector <long long> d(long long n) {
    vector <long long> v;

    if (n == 1) {
        v.push_back(1);
        return v;
    }

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) v.push_back(i);
        while (n % i == 0) n /= i;
    }

    if (n != 1) v.push_back(n);

    return v;
}


int main() {

    long long n, num, p = 1;
    cin >> n;
    vector <long long> v;

    for (long long i = 0; i < n; i++) {
        cin >> num;
        p *= num;
    }

    cout << d(p).size() << endl;

    return 0;

}
