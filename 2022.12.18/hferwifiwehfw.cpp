#include <bits/stdc++.h>
using namespace std;

vector <bool> sieve(1000001);
vector <long long> primes;

unordered_map <long long, int> dp;

void get_sieve() {
    sieve[0] = 1;
    sieve[1] = 1;

    for (int i = 2; i * i <= 1000000; i++) {
        if (sieve[i]) continue;

        for (int j = i * i; j <= 1000000; j += i) sieve[j] = 1;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (!sieve[i]) primes.push_back(i);
    }
}

bool is_prime(long long n) {
    if (n <= 1000000) return !sieve[n];

    for (int i : primes) {
        if (n % i == 0) return false;
    }

    return true;
}

long long f(long long n) {
    if (n == 0) return 0;
    if (dp.find(n) != dp.end()) return dp[n];

    long long ans = 0;

    for (long long p = 1; n / p; p *= 10) {
        long long x = n / (10 * p) * p + n % p;

        ans = max(ans, f(x));
    }

    if (is_prime(n)) ans++;
    dp[n] = ans;

    return ans;
}

void ex() {
    long long x;
    cin >> x;

    cout << f(x) << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    get_sieve();

    int n;
    cin >> n;

    while (n--) ex();

    return 0;

}
