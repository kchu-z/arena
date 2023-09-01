#include <bits/stdc++.h>
using namespace std;

int main() {

    int br = 0;

    for (int i = 1; i <= 2020; i += 3) {
        if (i % 7 == 0) {
            br++;
            if (i % 49 == 0) {
                br++;
                if (i % 343 == 0) br++;
            }
        }
    }

    cout << br << endl;
    return 0;

}
