#include <iostream>
using namespace std;

int main() {

    int m, n;
    char s;

    cin >> m >> n >> s;

    for (int i = 0; i < m; i++) {
        cout << s;
        for (int j = 2; j < n; j++) cout << s;
    }

    cout << s << endl;

    for (int i = 1; i < n - 1; i++) {
        for (int i = 0; i < m; i++) {
            cout << s;
            for (int j = 2; j < n; j++) cout << ' ';
        }

        cout << s << endl;
    }


    for (int i = 0; i < m; i++) {
        cout << s;
        for (int j = 2; j < n; j++) cout << s;
    }

    cout << s << endl;

    return 0;

}
