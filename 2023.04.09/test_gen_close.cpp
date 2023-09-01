#include <bits/stdc++.h>
using namespace std;


const int SIEVE_MAX = 10000;
const int N_MAX = 100000;

int v[N_MAX + 1];
vector <int> sieve[SIEVE_MAX + 1];

int main() {

    ofstream input;
    input.open("close.in");
    input << "";

    freopen("close.in", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    cout << endl;

    for (int i = 1; i <= SIEVE_MAX; i++) {
        for (int j = i; j <= SIEVE_MAX; j += i) {
            sieve[j].push_back(i);
        }
    }

    v[0] = rand() % SIEVE_MAX + 1;

    for (int i = 1; i < n; i++) {
        if (v[i - 1] == 1) v[i] = rand() % SIEVE_MAX + 1;
        else v[i] = sieve[v[i - 1]][rand() % (int) sieve[v[i - 1]].size()];
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] - k << ' ';
    }

    return 0;

}
