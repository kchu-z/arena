#include <bits/stdc++.h>
using namespace std;

void fill_v(vector <vector <bool>>& v) {
    int n = v.size();

    for (int i = 0; i < n; i++) {
        v[i][n - 1 - i] = 1;
        v[i][n - 1 + i] = 1;
    }

    int row = (n - 1) / 2, start = n - 1 - row, finish = n - 1 + row;
    for (int i = start; i <= finish; i++) v[row][i] = 1;
}

int main() {

    int n, br = 0;
    cin >> n;
    vector <vector <bool>> v(n, vector <bool> (2 * n - 1));

    fill_v(v);
    reverse(v.begin(), v.end());
    fill_v(v);
    reverse(v.begin(), v.end());

    for (auto& i : v) {
        for (bool x : i) {
            //cout << x << ' ';
            br += x;
        }
        //cout << endl;
    }

    cout << br << endl;
    return 0;

}
