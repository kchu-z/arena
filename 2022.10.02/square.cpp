#include <bits/stdc++.h>
using namespace std;
int arr[43];

vector <int> factor(int n) {
    vector <int> v;

    for (int i = 2; i * i <= n; i++) {
        int br = 0;

        while (n % i == 0) {
            br++;
            v.push_back(i);
            n /= i;
        }

        if (br > arr[i]) {
            arr[i] = br;
        }
    }

    if (n != 1) {
        v.push_back(n);
        if (1 > arr[n]) arr[n] = 1;
    }

    return v;
}

long long power(long long b, int n) {
    long long s = 1;
    for (int i = 0; i < n; i++) s *= b;
    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num, br = 0;
    cin >> n;
    long long p = 1;

    for (int i = 0; i < n; i++) {
        cin >> num;
        factor(num);
    }

    for (int i = 1; i <= 43; i++) {
        arr[i] += (arr[i] % 2);
        p *= power(i, arr[i] / 2);
    }

    cout << p;

    return 0;

}
