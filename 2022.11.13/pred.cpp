#include <bits/stdc++.h>
using namespace std;

struct int_1{
    int x = -1;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;
    unordered_map <int, int_1> m;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << m[num].x << ' ';
        m[num].x = i;
    }

    return 0;

}
