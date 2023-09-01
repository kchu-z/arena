#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double n;
    cin >> n;

    cout << (int) (n * 1000) % 10 << endl;

    return 0;

}
