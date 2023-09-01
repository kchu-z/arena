#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector <pair <pair <int, int>>, string> v(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int sum = 0;
        for (char j : s) sum += j[i];
    }

    return 0;

}
