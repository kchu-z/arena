#include <bits/stdc++.h>
using namespace std;

int factors[43];
bool visited[43];

vector <vector <int>> factorization{
    {},
    {},
    {2},
    {3},
    {2, 2},
    {5},
    {2, 3},
    {7},
    {2, 2, 2},
    {3, 3},
    {2, 5},
    {11},
    {2, 2, 3},
    {13},
    {2, 7},
    {3 5},
    {2, 2, 2, 2},
    {17},
    {2, 3, 3},
    {19},
    {2, 2, 5},
    {3, 7},
    {2, 11},
    {23},
    {2, 2, 2, 3},
    {5, 5},
    {2, 13},
    {3, 3, 3},
    {2, 2, 7},
    {29},
    {2, 3, 5},
    {31},
    {2, 2, 2, 2, 2},
    {3, 11},
    {2, 17},
    {5, 7},
    {2, 2, 3, 3},
    {37},
    {2, 19},
    {3, 13},
    {2, 2, 2, 5},
    {41},
    {2, 3, 7},

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, k, __nok = 1;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int x : edges[u])
    }

    cout << __nok << endl;
    return 0;

}

/**
42 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
*/
