#include <bits/stdc++.h>
using namespace std;

long long toNumber(string& s) {
    long long n = 0;
    for (char& i : s) n = n * 10 + i - '0';
    return n;
}

int main() {

    string s = "123001";
    cout << toNumber(s);

}
