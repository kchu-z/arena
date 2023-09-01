#include <bits/stdc++.h>
using namespace std;

const int SIEVE_MAX = 10000;
const int N_MAX = 100000;

int v[N_MAX + 1];
vector <int> sieve[SIEVE_MAX + 1];

vector <int> possible_values;

void check(int a, int b) {
    if (a > b) swap(a, b);
    cout << a << ' ' << b << ' ' << b - a << endl;
    if (a == b) return;
    /// a + k | b - a

    vector <int> current_values, intersection;

    for (int divisor : sieve[b - a]) {\
        cout << divisor << ' ';
        if (a <= divisor) current_values.push_back(divisor - a);
        cout << divisor - a << ' ';
    }

    cout << endl;

    for (int x : possible_values) {
        for (int y : current_values) {
            if (x == y) intersection.push_back(x);
        }
    }

    possible_values = intersection;
}


int main() {

    //freopen("close.in", "r", stdin);


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //double _time = clock();
    for (int i = 1; i <= SIEVE_MAX; i++) {
        for (int j = i; j <= SIEVE_MAX; j += i) {
            sieve[j].push_back(i);
        }
    }

    //cout << (clock() - _time) / CLOCKS_PER_SEC << endl;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int a = v[0], b = v[1];
    if (a > b) swap(a, b);

    for (int divisor : sieve[b - a]) {
        if (a <= divisor) possible_values.push_back(divisor - a);
    }

    cout << "BACK " << possible_values.front() << endl;

    for (int i = 1; i < n - 1; i++) {
        int a = v[i], b = v[i + 1];
        check(a, b);

        for (int x : possible_values) cout << x << ' ';
    }

    if (possible_values.size()) cout << possible_values.front() << endl;
    return 0;

}

