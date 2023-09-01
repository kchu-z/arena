#include <bits/stdc++.h>
using namespace std;

unsigned long long n, m, k, dp[1001][1001];
bool check[1001][1001];

unsigned long long f(int len, int last) {
    if (len == 0) return 1;
    if (last == m) return 0;

    if (check[len][last]) return dp[len][last];
    check[len][last] = 1;

    for (int i = 0; i < )
}

int main() {



    return 0;

}
