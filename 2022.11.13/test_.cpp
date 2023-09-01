#include <bits/stdc++.h>
using namespace std;

long long get2ndPower(long long x) {
    if (x == 0) return 1;
    return 2 * get2ndPower(x - 1);
}

string mul(string& s, long long n) {
    string ans;
    long long pr = 0;

    for (int i = 0; i < s.size() || pr; i++) {
        long long sum = (int) (s[i] - '0') * n + pr;
        pr = sum / 10;

        ans.push_back(sum % 10 + '0');
    }

    return ans;
}

string add(string& a, string& b) {
    string ans;
    bool pr = 0;

    for (int i = 0; i < a.size() || pr; i++) {
        int sum = a[i] - '0' + pr;
        if (i < b.size()) sum += b[i] - '0';

        if (sum > 10) {
            sum -= 10;
            pr = true;
        } else pr = false;

        ans.push_back(sum + '0');
    }

    return ans;
}

string sub(string& a, string& b) {
    string ans; /// a > b > 0
    bool pr = 0;

    for (int i = 0; i < a.size(); i++) {
        int sum = a[i] - '0' - pr;
        if (i < b.size()) sum -= b[i] - '0';

        if (sum < 0) {
            sum += 10;
            pr = true;
        } else pr = false;

        ans.push_back(sum + '0');
    }

    return ans;
}



int main() {

    long long p = 1;

    for (int i = 0; i < 30; i++) {

        cout << p << ", ";
        p *= 2;
    }

    return 0;

}
