#include <iostream>
using namespace std;

int main() {

    for (int n = 1; n * (n + 7) - 7 < 365; n++) cout << n << ' ' << n * (n + 7) - 7 << endl;

    return 0;

}
