#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long sum, n;
    char s;
    cin >> sum;

    while (cin >> s >> n) {
        if (s == '-') sum -= n;
        else sum += n;
    }

    cout << sum << endl;

    return 0;

}
