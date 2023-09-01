#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char s;
    int br = 0, num = 0;
    int a = 0, b = 0, c = 0;

    while (cin >> s) {
        if (br == 7) {
            if (num % 2 == 0) a++;
            else if (num % 3 == 0) b++;
            else if (num % 5 == 0) c++;

            num = 0;
        } else if (3 <= br && br <= 6) {
            num = num * 10 + (s - '0');
        }

        br = (br + 1) % 8;
    }

    cout << a << ' ' << b << ' ' << c << endl;
    return 0;

}
