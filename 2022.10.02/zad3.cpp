#include <bits/stdc++.h>
using namespace std;

bool simple(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {

    int n;
    cin >> n;


    if (n == 1) cout << "no";
    else if (simple(n)) cout << "yes";
    else cout << "no";

    return 0;

}
