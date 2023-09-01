#include <bits/stdc++.h>
using namespace std;

int main() {

    int diff = INT_MAX;
    vector <int> v(4);
    cin >> v[0] >> v[1] >> v[2] >> v[3];

    for (int i = 0; i < 16; i++) {
        int cmp = i;
        vector <int> s(2);

        for (int j = 0; j < 4; j++) {
            bool f = cmp % 2;
            s[f] += v[j];

            cmp /= 2;
        }

        diff = min(diff, abs(s[0] - s[1]));
    }

    cout << diff << endl;
    return 0;

}
