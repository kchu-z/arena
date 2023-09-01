#include <bits/stdc++.h>
using namespace std;

int exec(int n) {

    int br = 1, num;
    stack <int> s;

    for (int i = 0; i < n; i++) {
        cin >> num;
        for (br; br <= num; br++) s.push(br);

        if (s.top() == num) {
            s.pop();
        } else {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int __a = 0; __a < 5; __a++) {
        exec(n);
    }

    return 0;

}
