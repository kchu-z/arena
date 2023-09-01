#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;
    vector <int> v(1000);

    for (int i = 0; i < n; i++) {
        cin >> num;
        v[num]++;
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < v[i]; j++) cout << i << ' ';
    }

    return 0;

}
