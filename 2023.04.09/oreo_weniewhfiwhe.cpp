#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[100001], bits[64];

void add_bits(long long x) {
    for (int p = 0; p < 63; p++) {
        bits[p] += 1 - (x & 1);
        x >>= 1;
    }
}

void remove_bits(long long x) {
    for (int p = 0; p < 63; p++) {
        bits[p] -= 1 - (x & 1);
        x >>= 1;
    }
}

long long to_int() {
    long long ans = 0;

    for (int p = 0; p < 63; p++) {
        ans += (1 << p) * (bits[p] == 0);
    }

    return ans;
}

bool check(long long x) {
    add_bits(x);

    long long ans = to_int() >= k;
    remove_bits(x);

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long j = -1;
    long long ans = 0;

    for (long long i = 0; i < n; i++) {
        while (j + 1 < n && check(a[j + 1])) {
            add_bits(a[j + 1]);
            j++;
        }

        ans += j + 1 - i;

        if (j >= i) {
            remove_bits(a[i]);
        } else {
            j++;
        }
    }

    cout << ans << endl;
    return 0;

}
/**
10 6
8 2 14 6 8 3 4 5 7 9
*/
/**
42 69
335 501 170 725 479 359 963 465 706 146 282 828 962 492 996 943 828 437 392 605 903 154 293 383 422 717 719 896 448 727 772 539 870 913 668 300 36 895 704 812 323 334
*/
