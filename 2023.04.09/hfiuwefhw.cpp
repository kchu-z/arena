#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
    if (n == 1) return 1;
    return fact(n - 1) * n;
}

int main() {

    srand(time(0));

    long long n;
    cin >> n;

    vector <long long> v;

    for (long long i = 1; i <= n; i++) {
        v.push_back(i);
    }

    long long random = rand() % fact(n);

    for (long long i = 0; i < random; i++) {
        next_permutation(v.begin(), v.end());
    }

    for (long long x : v) cout << x << ' ';
    cout << '\n';

    return 0;

}
/**
1 2 9 4 3 10 5 8 7 6
7 2 1 4 6 5 8 3
*/
