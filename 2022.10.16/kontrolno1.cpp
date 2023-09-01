#include <bits/stdc++.h>
using namespace std;

struct fraction{
    double first, second;
};

bool cmp(fraction a, fraction b) {
    if (a.first / a.second != b.first / b.second) return a.first / a.second < b.first / b.second;
    return a.first < b.first;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char s;
    int i = 0;
    double a, b;
    vector <fraction> v;

    while (cin >> a) {
        cin >> s >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);

    for (fraction i : v) {
        cout << i.first << '/' << i.second << ' ';
    }

    return 0;

}
