#include <bits/stdc++.h>
using namespace std;

vector <long long> v(55, 1);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 54; i++) v[i] = v[i - 1] * 2;

    long long n, br = 0;
    cin >> n;

    for (int i = 0; i <= 54; i++) {
        long long sum = 0;

        for (int j = i; j <= 54; j++) {
            sum += v[j];

            if (sum <= n) br++;
        }
    }

    cout << br << endl;
    return 0;

}
