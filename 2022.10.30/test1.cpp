#include <bits/stdc++.h>
using namespace std;

bool isSymmetric(string& a) {
    for (int i = 0; i < a.size() / 2; i++) {
        if (a[i] != a[a.size() - i - 1]) return false;
    }

    return true;
}

int main() {

    string n;
    cin >> n;

    cout << isSymmetric(n);

    return 0;

}
