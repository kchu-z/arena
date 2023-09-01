#include <iostream>
using namespace std;

void ex(int n) {
    if (n == 1 || n == 2 || n == 5) cout << "NO\n";
    else {
        for (int i = n / 4; i >= 0; i--) {
            if ((n - 4 * i) % 3 == 0) {
                cout << i << ' ' << (n - 4 * i) / 3 << endl;
                break;
            }
        }
    }
}

int main() {

    int x;
    cin >> x;

    while (x != 0) {
        ex(x);
        cin >> x;
    }

    return 0;

}
