#include <bits/stdc++.h>
using namespace std;

vector <int> v;

int bs_1(int n) {
    int l = 0, r = v.size() - 1;
    int maxidx = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (n <= v[m]) r = m - 1;
        else {
            maxidx = max(maxidx, m);
            l = m + 1;
        }
    }

    return v.size() - maxidx - 1;
}

int bs_2(int n) {
    int l = 0, r = v.size() - 1;
    int minidx = v.size();

    while (l <= r) {
        int m = (l + r) / 2;

        if (n >= v[m]) l = m + 1;
        else {
            minidx = min(minidx, m);
            r = m - 1;
        }
    }

    return minidx;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    vector <int> upper(100001, -1), lower(100001, -1);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());
    cin >> m;

    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;

        if (upper[left] == -1) {
            upper[left] = bs_1(left);
            lower[left] = bs_2(left);
        }

        if (upper[right] == -1) {
            upper[right] = bs_1(right);
            lower[right] = bs_2(right);
        }

        cout << upper[left] + lower[right] - n << '\n';
    }

    return 0;

}
