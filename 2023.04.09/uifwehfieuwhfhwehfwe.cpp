#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> bezu(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto p = bezu(b, a % b);
    return {p.second, p.first - p.second * (a / b)};
}

int main() {

    long long a, b;
    cin >> a >> b;

    auto p = bezu(a, b);
    cout << p.first << ' ' << p.second << endl;

    return 0;

}
