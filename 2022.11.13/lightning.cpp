#include <iostream>
using namespace std;

int main() {

    int n;
    char s, b;
    cin >> n >> s >> b;

    if (b == '/') {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) cout << ' ';
            cout << s << endl;
        }

        for (int j = 0; j < n; j++) cout << s;
        cout << endl;

        for (int i = n - 1; i > 0; i--) {
            for (int j = 1; j < i; j++) cout << ' ';
            cout << s << endl;
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < i; j++) cout << ' ';
            cout << s << endl;
        }

        for (int j = 0; j < n; j++) cout << s;
        cout << endl;

        for (int i = 0; i < n - 1; i++) {
            for (int j = -1; j < i; j++) cout << ' ';
            cout << s << endl;
        }
    }

    return 0;

}
