#include <bits/stdc++.h>
using namespace std;

long long getNumber(vector <pair <int, int>> prime_factors) {
    long long num = 1;

    for (auto& p : prime_factors) {
        for (int i = 0; i < p.second; i++) num *= p.first;
    }

    return num;
}

int main() {

    int n, a, b;
    cin >> n;

    vector <int> prime_factors;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        prime_factors.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {

    }

    return 0;

}
