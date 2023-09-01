#include <bits/stdc++.h>
using namespace std;

long long a[1000];
bool sieve[500001];
vector <int> primes;

vector <int> get_divisors(long long n) {
    vector <int> ans;

    for (auto k : primes) {
        if (n < k * k) break;

        if (n % k == 0) {
            ans.push_back(k);
            while (n % k == 0) n /= k;
        }
    }

    if (n != 1) ans.push_back(n);
    return ans;
}

vector <int> f(long long n) {
    if (n < 0) return {};
    auto past_divisors = f(n - 1);
    n = a[n];

    for (auto x : past_divisors) {
        while (n % x == 0) n /= x;
    }

    auto ans = get_divisors(n);
    for (auto x : past_divisors) ans.push_back(x);
    return ans;
}

int main() {

    for (int a = 2; a <= 500000; a++) {
        if (!sieve[a]) {
            primes.push_back(a);

            for (int b = 2 * a; b <= 500000; b += a) sieve[b] = 1;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    cout << f(n - 1).size() << endl;
    return 0;

}
