#include <bits/stdc++.h>
using namespace std;

vector <bool> sieve(10000001);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, br = 0;
    cin >> n;

    for (int i = 1; i * i <= 10000000; i++) {
        for (int j = i; i * i + j * j <= 10000000; j++) {
            sieve[i * i + j * j] = true;
        }
    }


    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (sieve[num]) br++;
    }

    cout << br << endl;
    return 0;

}

