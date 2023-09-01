#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, m;
    cin >> n >> m;

    vector <pair <long long, long long>> v(n);

    priority_queue <pair <long long, long long>> busy;
    priority_queue <long long> free;

    for (long long i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].second *= -1;
    }

    sort(v.begin(), v.end());

    return 0;

}
