#include <bits/stdc++.h>
using namespace std;

long long a[1000001];
long long n, k;

vector <long long> cannon;
vector <pair <long long, int>> divisors;
unordered_map <long long, int> prefix[1000001];

bool check(long long l, long long r) {
    for (auto p : divisors) {
        if (p.second > prefix[r][p.first] - prefix[l - 1][p.first]) return 0;
    }

    return 1;
    //return (prefix[r] / prefix[l - 1]) % k != 0;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long br = 0;

    long long k1 = k;

    for (long long i = 2; i * i <= k; i++) {
        while (k % i == 0) {
            k /= i;
            cannon.push_back(i);
        }
    }

    if (k != 1) cannon.push_back(k);
    sort(cannon.begin(), cannon.end());

    for (int i = 0; i < cannon.size(); i++) {
        br++;
        if (i + 1 == cannon.size() || cannon[i] != cannon[i + 1]) {
            divisors.push_back({cannon[i], br});
            br = 0;
        }
    }
/**
    for (auto p : divisors) {
        cout << p.first << ' ' << p.second << endl;
    }
    cout << endl;
*/
    k = k1;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        unordered_map <long long, int> current;

        for (auto p : divisors) {
            long long divisor = p.first, br = 0;

            while (a[i] % divisor == 0) {
                br++;
                a[i] /= divisor;
            }

            current[divisor] = br;
        }

        for (auto p : current) {
            prefix[i][p.first] = prefix[i - 1][p.first] + p.second;
        }

        /**cout << i << endl;
        for (auto p : prefix[i])
            cout << p.first << ' ' << p.second << endl;
        cout << endl;*/
    }

    long long j = 0;

    for (long long i = 1; i <= n; i++) {
        while (j < n && !check(i, j + 1)) j++;

        ///cout << i << ' ' << j + 1 << endl;
        br += n - j;

        if (j < i) j = i;
    }

    cout << br << endl;
    return 0;

}

