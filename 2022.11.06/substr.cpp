#include <bits/stdc++.h>
using namespace std;

int main() {

    string a, b, s;
    cin >> a >> b;
    vector <int> v1(26), v2(26);

    for (char& i : a) {
        v1[i - 'a']++;
    }

    for (char& i : a) {
        v2[i - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int n = min(v1[i], v2[i]);
        for (int j = 0; j < n; j++) s.push_back(i + 'a');
    }

    cout << s;

    return 0;

}
