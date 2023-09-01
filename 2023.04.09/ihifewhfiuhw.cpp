#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map <int, bool> s;

    for (long long i = 1; i <= 2009; i++) s[i * i / 2010] = 1;

    cout << s.size() << endl;

    return 0;

}
