#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pair <int, int> majorant;

    int n;
    cin >> n >> majorant.first;
    majorant.second = 1;

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;

        if (majorant.second == 0) {
            majorant = {x, 1};
            continue;
        }

        if (x == majorant.first) {
            majorant.second++;
        } else {
            majorant.second--;
        }

        //cout << majorant.first << ' ' << majorant.second << endl;
    }

    cout << majorant.first << endl;
    return 0;

}
