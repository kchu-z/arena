#include <iostream>
using namespace std;

int main() {

    int a, b;
    char s;
    cin >> a >> b >> s;

    if (s == '+') cout << a + b << endl;
    else if (s == '-') cout << a - b << endl;
    else cout << a * b << endl;

    return 0;

}
