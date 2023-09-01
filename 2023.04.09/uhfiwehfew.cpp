#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, m, br = 0;
    cin >> n;
    m = n;

    vector <int> div;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i * i != n) div.push_back(n / i);
        }
    }

    for (int i = 0; i < div.size(); i++) {
        for (int j = i; j < div.size(); j++) {
            for (int z = j; z < div.size(); z++) {
                //cout << div[i] << ' ' << div[j] << ' ' << div[z] << endl;
                if (div[i] * div[j] * div[z] == m) br++;
            }
        }
    }

    cout << br << endl;
    return 0;

}
