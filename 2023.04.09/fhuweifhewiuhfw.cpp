#include <bits/stdc++.h>
using namespace std;

vector <pair <long long, int>> divisors;

void add_back() {
    divisors.back() = {divisors.back().first, divisors.back().second + 1};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, gcd = 0;
    cin >> n;


    if (n % 2 == 0) {
        divisors.push_back({2, 0});

        while (n % 2 == 0) {
            n /= 2;
            add_back();
        }
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            divisors.push_back({i, 0});

            while (n % i == 0) {
                n /= i;
                add_back();
            }

            gcd = __gcd(gcd, divisors.back().second);
        }
    }

    if (n != i) {
        divisors.push_back({n, 1});
        gcd = 1;
    }


    return 0;

}
