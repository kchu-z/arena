#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, num, k;
    cin >> n >> k;
    unordered_map <long long, bool> v;
    for (int i = 0; i < k; i++) {
        cin >> num;
        v[num] = true;
    }
    cout << n - v.size() << endl;
    return 0;
}
