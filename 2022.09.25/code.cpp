#include <bits/stdc++.h>
using namespace std;

string s;

void pb(int num) {
    while (num) {
        s.push_back(num % 10);
        num /= 10;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string v;
    cin >> v;
    v.pop_back();
    int br = 0, n = v.size();

    for (int i = 0; i < n; i++) {
        br++;
        if (i == n - 1 || v[i] != v[i + 1]) {
            if (br != 1) pb(br);
            s.push_back(v[i]);
            br = 0;
        }
    }
    cout << endl << n - s.size();

    return 0;

}

