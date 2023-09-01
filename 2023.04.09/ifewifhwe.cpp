#include <bits/stdc++.h>
using namespace std;

int main() {

    srand(time(0));

    int n = rand() % 20 + 1;
    int k = rand() % 20 + 1;

    cout << n << ' ' << k << endl;

    for (int i = 0; i < n; i++) {
        cout << rand() % 100 + 1 << ' ';
    }

    return 0;

}
/**
42 68
335 501 170 725 479 359 963 465 706 146 282 828 962 492 996 943 828 437 392 605 903 154 293 383 422 717 719 896 448 727 772 539 870 913 668 300 36 895 704 812 323 334
*/
