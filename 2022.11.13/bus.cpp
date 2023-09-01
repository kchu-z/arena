#include <bits/stdc++.h>
using namespace std;

int main() {

    long long minD, maxD, nok;
    cin >> minD >> maxD >> nok;

    long long newA = minD + nok - (minD % nok);
    long long newB = maxD - (maxD % nok);

    if (minD % nok == 0) newA = minD;

    ///cout << nok << endl << minD << ' ' << maxD << endl;
    ///cout << newA << ' ' << newB << endl;
    cout << (newB - newA) / nok + 1;

    return 0;

}
