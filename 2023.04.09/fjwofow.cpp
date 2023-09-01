#include <bits/stdc++.h>
using namespace std;

long long a[1000001], prefix[1000001];
long long n, k;

vector <int> cannon;
vector <pair <int, int>> divisors;

bool check(long long l, long long r) {
    return (prefix[r] / prefix[l - 1]) % k != 0;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;

}


