#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    n = (n - 1) / 2;

    vector <int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int i = 0, j = 0;

    while (a[i] != b[j]) {
        if (a[i] < b[j]) i++;
        else j++;
    }

    cout << i + j + 2 << endl;

    return 0;

}
