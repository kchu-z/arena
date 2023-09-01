#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, ans;
    cin >> n >> ans;

    for (int i = 1; i < n; i++) {
        long long num;
        cin >> num;

        ans = (ans ^ num);
    }

    cout << ans << endl;
    return 0;

}
