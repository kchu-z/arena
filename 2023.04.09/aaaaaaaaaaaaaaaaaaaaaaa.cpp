#include <bits/stdc++.h>
using namespace std;

bool verify(int t[]) {
    for (int i = 0; i < 9; i++) for (int j = i + 1; j < 9; j++) if (t[i] > 9 || t[j] > 9 || t[i] == t[j]) return false; return true;
}

int main() {

    for (int i = 5; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                for (int l = 5; l <= 9; l++) {
                    int t[9] = {14 - i, 14 - j - k, 14 - l, i, j, k, l, 14 - i - j, 14 - k - l};

                    if (verify(t)) {
                        cout << t[0] << endl;
                        cout << t[1] << endl;
                        cout << t[2] << endl;
                        cout << t[3] << endl;
                        cout << t[4] << endl;
                        cout << t[5] << endl;
                        cout << t[6] << endl;
                        cout << t[7] << endl;
                        cout << t[8] << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;

}
