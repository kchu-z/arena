#include <bits/stdc++.h>
using namespace std;
int n;
int a[50];
bool used[50];

vector <vector <int>> ans;

void brute_force(int pos) {
    if (pos == 0) {
        vector <int> v;

        for (int i = 1; i < 50; i++) {
            if (a[i] == 0) continue;
            v.push_back(a[i]);
        }

        ans.push_back(v);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = true;
        a[pos] = i;
        brute_force(pos - 1);
        used[i] = false;
    }
}

int main() {

    cin >> n;
    brute_force(n);
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    sort(ans.begin(), ans.end());

    for (auto x : ans) {
        for (int i : x) cout << v[i - 1] << ' ';
        cout << endl;
    }

    return 0;

}
