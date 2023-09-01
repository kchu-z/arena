#include <bits/stdc++.h>
using namespace std;

string mul(string& s, long long p){
    string res;
    int prenos = 0;

    for(int i = 0; i < s.size() || prenos; i++){
        long long curr = prenos;
        if(i < s.size()) curr += (s[i] - '0') * p;

        res.push_back(curr % 10 + '0');
        prenos = curr / 10;
    }

    return res;
}

int main() {

    int n;
    cin >> n;

    string s = "1";

    for (int i = 2; i <= n; i++) {
        s = mul(s, i);
    }

    int sum = 0;

    for (char& i : s) sum += i - '0';
    cout << sum << endl;

    return 0;

}
