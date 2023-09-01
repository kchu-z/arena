#include <bits/stdc++.h>
using namespace std;

const int bitsize = 31;
long long n, k, br = 0;

vector <int> main_bits(bitsize), v(100000);
vector <int> main_bits0(bitsize);

void add(long long n, long long p) {
    vector <int> bits(bitsize);

    for (int i = 0; i < bitsize; i++) {
        bits[i] = n % 2;
        n /= 2;
    }

    for (int i = 0; i < bitsize; i++) {
        main_bits[i] += bits[i] * p;
    }
}

long long get_integer(vector <int>& bits) {
    long long n = 0;

    for (int i = bitsize - 1; i >= 0; i--) {
        n = n * 2 + (bool) bits[i];
    }

    return n;
}

bool check(long long a) {
    return (get_integer(main_bits) | a) < k;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> v[i];

    int j = -1;

    for (int i = 0; i < n; i++) {
        while (j + 1 < n && check(v[j + 1])) {
            add(v[j + 1], 1);
            j++;
        }

        //cout << i << ' ' << j << endl;

        if (i <= j) {
            add(v[i], -1);
            br += n - j - 1;
        } else {
            j = i;
            br += n - i;
        }
    }

    cout << br << endl;
    return 0;

}
