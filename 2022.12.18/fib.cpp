#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m = 0;
    cin >> n >> m;

    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    map <pair <int, int>, int> mp;

    vector <int> v{1, 1};

    for (int i = 2; !mp[{v[v.size() - 1], v[v.size() - 2]}]; i++) {
        mp[{v[v.size() - 1], v[v.size() - 2]}] = i;
        v.push_back((v[v.size() - 1] + v[v.size() - 2]) % m);

        //cout << v[v.size() - 1] << ' ' << v[v.size() - 2] << endl;
    }

    //for (int i : v) cout << i << ' ';

    v.pop_back();
    v.pop_back();

    cout << v[(n - 1) % v.size()] << endl;


    return 0;

}
