#include <iostream>
using namespace std;

int main() {

    long long n, num;
    cin >> n >> num;
    long long mx = num, mn = num;

    for (int i = 1; i < n; i++) {
        cin >> num;

        mx = max(mx, num);
        mn = min(mn, num);
    }

    cout << mn << ' ' << mx << endl;
    return 0;

}

