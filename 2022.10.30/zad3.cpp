#include <bits/stdc++.h>
using namespace std;

long long prime(string& s) {

    reverse(s.begin(), s.end());

    long long n = 0;
    for (char& i : s) n = (n * 10) + (s - '0');

    return n;
}
