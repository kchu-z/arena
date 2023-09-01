#include <bits/stdc++.h>
using namespace std;

long long d(long long n) {
    long long p = 1;

    for (long long i = 2; i * i <= n; i++) {
        long long br = 1;
        while (n % i == 0) {
            br++;
            n /= i;
        }

        p *= br;
    }

    if (n != 1) p *= 2;

    return p;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, q;
    cin >> n >> q;
    vector <long long> a(n), b(n);

    stack <long long> v, st;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[n - i - 1] = a[i];
    }

    for (int i = 0; 2 * i < n; i++) v.push(abs(a[i] - b[i]));

    while (!v.empty()) {
        if (st.empty()) st.push(v.top());
        else st.push(__gcd(st.top(), v.top()));

        v.pop();
    }

    cout << d(st.top()) << '\n';

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x, y;
            cin >> x >> y;

            st.push(__gcd(st.top(), abs(x - y)));
        } else st.pop();

        cout << d(st.top()) << '\n';

    }

    return 0;

}
/// 5 3 13 24 22 44 23 1 12 14 2 2
