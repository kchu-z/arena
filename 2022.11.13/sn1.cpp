#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char a[20], b[20];
    cin >> a >> b;

    strcat(b, a);
    cout << b << endl;

    return 0;

}
