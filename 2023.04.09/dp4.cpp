#include <bits/stdc++.h>
using namespace std;

int p;

long long f(int n, int s) {
    if (s < 0) return 0;
    if (n == 1) return s < p;

    long long ans = 0;

    for (int i = 0; i < p; i++) {
        ans += f(n - 1, i);
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> p >> s;

    cout << f(n - 1, s - 1);
    return 0;

}
