#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    vector <int> v{1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8};

    for (char& i : s) {
        if (isalpha(i)) cout << v[i - 'A'] + 1;
        else cout << i;
    }

    return 0;

}
