#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int a[21];

void print() {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

void brute(int pos, int k) {
    if (pos == 0) {
        if (k == 0) print();
        return;
    }

    if (k > 0) {
        v.push_back(a[pos]);
        brute(pos - 1, k - 1);
        v.pop_back();
    }

    if (pos > k) {
        brute(pos - 1, k);
    }
}

int main() {

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    brute(n, k);

    return 0;

}
