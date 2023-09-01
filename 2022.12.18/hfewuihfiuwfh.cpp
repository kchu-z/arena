#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b) {
    return a + b > b + a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <string> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);

    for (string& str : v) cout << str;

    return 0;

}
