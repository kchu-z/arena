#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, sum = 0;
    cin >> n;

    vector <pair <int, int>> prime_factors;

    int N = n;
    for (int i = 2; i * i <= n; i++) {
        int br = 0;

        while (n % i == 0) {
            n /= i;
            br++;
            sum += i;
        }

        if (br) prime_factors.push_back({i, br});
    }



    if (n != 1) {
        sum += n;
        prime_factors.push_back({n, 1});
    }

    if (prime_factors.size() == 1 && prime_factors[0].second == 1) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < N - sum; i++) {
        cout << 1 << ' ';
    }

    for (auto p : prime_factors) {
        for (int i = 0; i < p.second; i++) cout << p.first << ' ';
    }

    return 0;

}
