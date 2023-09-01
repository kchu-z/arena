#include <bits/stdc++.h>
using namespace std;

long long a[1000000], sol[1000000];
vector <pair <int, pair <int, int>>> dq;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, range = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }


    for (int i = n - 1; i >= 0; i--) {
        while (dq.size() && dq.back().first <= a[i]) dq.pop_back(); /// yes
        dq.push_back({a[i], i});

        range = bs(0, dq.size() - 1, i);
        if (range == 0) sol[i] = i;
        else if (range == dq.size()) sol[i] = n;
        else sol[i] = dq[range].second;


    }

    for (int i = 0; i < n; i++) {
        cout << sol[i] - i << ' ';
    }

    return 0;

}



