#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, sum = 0;
    cin >> n;

    vector <long long> even, odd;

    for (int i = 0; i < 2 * n; i++) {
        long long num;
        cin >> num;

        if (num % 2 == 0) even.push_back(num);
        else odd.push_back(num);
    }

    for (int i = 0; i < n; i++) sum += abs(even[i] - odd[i]);
    cout << sum << endl;

    return 0;

}

