#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    cin >> str;

    stack <int> s;
    int maxdiff = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') s.push(i);
        else {
            maxdiff = max(maxdiff, i - s.top());
            s.pop();
        }
    }

    cout << maxdiff << endl;
    return 0;

}
