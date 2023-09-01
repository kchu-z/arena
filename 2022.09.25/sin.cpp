#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string v;
    cin >> v;
    int n = v.size(), br = 0, m = 0;
    char s;

    for (int i = 0; i < n; i++) {
        br++;
        if (i == n - 1 || v[i] != v[i + 1]) {
            if (m < br) {
                m = br;
                s = v[i];
            }

            br = 0;
        }
    }

    cout << m << ' ' << s << endl;

    return 0;

}
