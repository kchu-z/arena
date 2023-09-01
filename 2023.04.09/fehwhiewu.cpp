#include <iostream>
using namespace std;

int ex(int n) {
    int br = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) br++;
    }

    return br;
}

int main() {

    int n, br = 0, num = 0;
    cin >> n;

    for (n; n != 0; cin >> n) {
        int temp = ex(n);

        if (temp > br) {
            br = temp;
            num = n;
        }
    }

    cout << num << ' ' << br << endl;
    return 0;

}
