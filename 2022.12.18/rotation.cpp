#include <bits/stdc++.h>
using namespace std;
int n, k;

void rotate_90(int N, int arr[]) {
    int tbl[N][N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tbl[j][n - i - 1] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = tbl[i][j];
        }
    }
}

int main() {

    cin >> n >> k;
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k % 4; i++) {
        rotate_90(n, arr);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;

}
