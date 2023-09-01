#include <bits/stdc++.h>
using namespace std;

int main() {

    string str, msg;
    cin >> str;

    getline(cin, msg);

    char arr[5][5];
    int i, j = 'A';
    bool is[256];

    for (i = 0; i < str.size(); i++) {
        if (is[str[i]]) continue;
        arr[i / 5][i % 5] = str[i];
        is[str[i]] = true;
    }

    vector <pair <char, char>> v;



    return 0;

}
