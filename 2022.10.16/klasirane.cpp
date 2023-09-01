#include <bits/stdc++.h>
using namespace std;

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector <pair <int, int>> v(4);

    v[0] = {1 - a, a};
    v[1] = {2 - b, b};
    v[2] = {3 - c, c};
    v[3] = {4 - d, d};

    sort(v.begin(), v.end());

    cout << v[0].second << ' ' << v[1].second << ' ' << v[2].second << ' ' << v[3].second << endl;

    return 0;

}
