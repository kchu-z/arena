#include <bits/stdc++.h>
using namespace std;
map <int, bool> table;
vector <int> v(10, 1);

bool isWhole(double s) {
    return s == floor(s);
}

int mx = 0;

void rec(int n) {
    if (n == 10) {
        int br = 0;

        for (int i = 0; i < 10; i++) {
            if (isWhole(v[i] * 1.0 / v[(i + 1) % 10])) br++;
        }

        mx = max(mx, br);
    } else {
        n++;
        for (int a = 1; a <= 10; a++) {
            if (!table[a]) continue;
            table[a] = false;
            v[n] = a;
            rec(n);
            table[a] = true;
        }
    }
}

int main() {

    rec(0);
    cout << mx;

    return 0;

}
