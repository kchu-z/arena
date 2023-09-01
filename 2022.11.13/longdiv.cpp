#include <bits/stdc++.h>
using namespace std;

string long_division(string& s, long long n) {
    string ans;
    long long pr = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        long long quotient = pr * 10 + (s[i] - '0');
        pr = quotient % n;
        quotient /= n;

        if (quotient || !ans.empty()) ans.push_back(quotient + '0');
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    return 0;

}
