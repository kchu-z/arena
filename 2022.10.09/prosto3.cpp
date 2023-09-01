#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {

    int a, b;
    cin >> a >> b;
    vector <int> v(b + 1, true);
    v[0] = false;

    if (a == 1) a++;

    for (int i = 2; i <= b; i++) {
        if (v[i]) {
            for (int j = 2 * i; j <= b; j += i) {
                v[j] = false;
            }
        }
    }

    for (int i = a; i <= b; i++) {
        int num = i;

        while (v[num]) num /= 10;
        if (num == 0) cout << i << endl;
    }

    return 0;

}
