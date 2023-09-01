#include <bits/stdc++.h>
using namespace std;

int main() {

    vector <int> v(5);
    cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
    sort(v.begin(), v.end());

    if (v[0] + 1 == v[1] && v[1] + 1 == v[2] && v[2] + 1 == v[3] && v[3] + 1 == v[4]) {
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << ' ' << v[4] << endl;
    } else cout << v[4] << endl;

    return 0;

}
