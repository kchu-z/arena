#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector <int> nums(N + 1);
    int n = 0;

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        n = max(n, nums[i]);
    }

    vector <int> v(n + 1);

    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= n; j += i) {
                v[j] = i;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << v[nums[i]] << ' ';
    }

    return 0;

}
