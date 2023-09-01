#include <iostream>
using namespace std;

int n, a;

bool check(int x, int y) {
    return max(abs(x), abs(y)) > a;
}

int main() {

    int mn = 0;
    bool f = false;

    cin >> n >> a;
    a /= 2;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (check(x, y)) {
            if (f) mn = min(mn, abs(x) + abs(y));
            else {
                f = true;
                mn = abs(x) + abs(y);
            }
        }
    }

    cout << mn << endl;
    return 0;

}
