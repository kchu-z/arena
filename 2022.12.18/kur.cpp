#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <int> p(n), v(n);

    for (int i = 0; i < n; i++) cin >> p[i];

    int i = 0;

    while (v[i] < 3) {
        v[i]++;
        i = p[i];
    }

    int zero = 0, one = 0, two = 0;

    for (int i : v) {
        if (i == 0) zero++;
        else if (i == 1) one++;
        else two++;
    }

    cout << one << ' ' << two << ' ' << zero << endl;
    return 0;

}
