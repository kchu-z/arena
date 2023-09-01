#include <bits/stdc++.h>
using namespace std;

int a[100], A, B;
bool check[100][101], check_num[101];

int f(int n, int k) {
    if (B < k) return 0;

    if (n < 0) {
        if (A <= k && !check_num[k]) {
            check_num[k] = 1;
            return 1;
        }

        return 0;
    }

    if (check[n][k]) return 0;
    check[n][k] = true;

    return max(f(n - 1, k + a[n]) + 1, f(n - 1, k));
}

int main() {

    int n;
    cin >> n >> A >> B;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    cout << f(n - 1, 0) << endl;
    return 0;

}

/**
7 3 6
10 8 2 3 10 5 5
*/
