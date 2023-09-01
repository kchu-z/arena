#include <bits/stdc++.h>
using namespace std;

int randomNumber(int min_e, int max_e) {
    return rand() % (max_e - min_e + 1) + min_e;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string file_name, s;
    int tests = 0;
    cin >> file_name;

    srand(time(0));

    for (int i = 1; i <= tests; i++) {
        ofstream os;
        os.open(file_name + ".in");

        while (cin >> s ) {
            if (s == "int") {
                int cnt, min_e, max_e;
                cin >> cnt >> min_e >> max_e;
                os << randomNumber(min_e, max_e);

                for (int i = 0; i < cnt; i++) {
                    os << ' ' << randomNumber(min_e, max_e);
                }
            }

            if (s == "end") break;
            if (s == "\\n") os << "\n";
        }

        os.close();
    }

    return 0;

}
