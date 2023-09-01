#include <bits/stdc++.h>
using namespace std;

vector <string> v;

void f(string a, string b) {
    if (b.size() == 1) {
        v.push_back(a + b);
        cout << a + b << endl;
    } else {
        for (int i = 0; i < b.size(); i++) {
            string newStr = b;
            newStr.erase(i);
            string newA = a;
            newA.push_back(b[i]);

            f(newA, newStr);
        }
    }
}

int main() {

    string s;
    cin >> s;

    f("", s);
    sort(v.begin(), v.end());

    //for (string& i : v) cout << i << ' ';

    return 0;

}
