#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;
    vector <int> v(n);
    stack <int> s;

    for (int i = 0; i < n; i++) cin >> v[i];
    reverse(v.begin(), v.end());


    for (int i = 0; i < n; i++) {
        num = v[i];
        while (!s.empty() && s.top() <= num) s.pop();

        if (s.empty()) v[i] = -1;
        else v[i] = s.top();

        s.push(num);
    }

    reverse(v.begin(), v.end());
    for (int i : v) cout << i << ' ';

    return 0;

}
