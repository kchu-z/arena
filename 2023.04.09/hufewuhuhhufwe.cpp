#include <iostream>
using namespace std;

int arr[201][201], prefix[201][201];

int area(int x1, int y1, int x2, int y2) {
    return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
}

int main() {

    int n, ar = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int r1 = 1; r1 <= n; r1++) {
        for (int r2 = r1 + 1; r2 <= n; r2++) {
            int j = 0;

            for (int i = 1; i <= n; i++) {
                while (j + 1 <= n && area(r1, i, r2, j + 1) == 0) {
                    j++;
                }

                ar = max(ar, (r2 - r1 + 1) * (j - i + 1));

                if (j < i) j = i;
            }
        }
    }

    cout << ar << endl;
    return 0;

}
