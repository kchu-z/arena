#include <bits/stdc++.h>
using namespace std;

vector <int> v;

int bs_1(int n) { /// за числа, по-големи или равни от n
    int l = 0, r = v.size() - 1;
    int maxidx = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (n <= v[m]) r = m - 1;
        else {
            maxidx = max(maxidx, m);
            l = m + 1;
        }
    }

    return v.size() - maxidx - 1;
}

int bs_2(int n) { /// за числа, по-малки или равни от n
    int l = 0, r = v.size() - 1;
    int maxidx = v.size();

    while (l <= r) {
        int m = (l + r) / 2;

        if (n >= v[m]) l = m + 1;
        else {
            minidx = max(minidx, m);
            r = m - 1;
        }
    }

    return maxidx;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        cout << bs_1(x) << endl;

    }

    return 0;

}
