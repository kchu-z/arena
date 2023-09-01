#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);

    int n;
    //cin >> n;

    double start = clock();

    for (int i = 0; i < 100000000; i++) {
        int x = rand() % 1000000 * (rand() % 1000000);
    }

    start = clock() - start;
    cout << start / CLOCKS_PER_SEC << endl;

    double start2 = clock();

    for (int i = 0; i < 100000000; i++) {
        int x = rand () % 1000000 / (abs(rand() % 1000000) + 1);
    }

    start2 = clock() - start;
    cout << start2 / CLOCKS_PER_SEC;
    cout << endl << start2 / start;


    return 0;

}
