#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, pos, num, sum = 0;
    cin >> n >> pos;
    vector <long long> v(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> num;
        v[i] = v[i - 1] + num;
    }

    long long minPos = pos, maxPos = pos;

    for (int i = 0; i < n - 1; i++) {
        if (minPos == 1) {
            sum += v[maxPos + 1] - v[pos];

            maxPos++;
            pos = maxPos;
        } else if (maxPos == n) {
            sum += v[pos] - v[minPos - 1];

            minPos--;
            pos = minPos;
        } else {
            if (v[pos] - v[minPos - 1] <= v[maxPos + 1] - v[pos]) {
                sum += v[pos] - v[minPos - 1];

                minPos--;
                pos = minPos;
            } else {
                sum += v[maxPos + 1] - v[pos];

                maxPos++;
                pos = maxPos;
            }
        }
    }

    cout << sum << endl;
    return 0;

}
