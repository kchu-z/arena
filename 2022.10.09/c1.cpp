#include <iostream>
using namespace std;

int main() {

    int n, br = 0, mx = 0;
    cin >> n;
    int arr[100];

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) br++;
        if (i == n - 1 || arr[i + 1] <= 0) {
            if (mx < br) mx = br;
            br = 0;
        }
    }

    cout << mx << endl;

    return 0;

}
