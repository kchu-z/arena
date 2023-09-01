#include <iostream>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int* pa;
    pa = new int[n];

    for (int i = 0; i < n; i++) {
        (*(pa + i)) = i;
    }

    for (int i = 0; i < n; i++) {
        //cout << (*(pa + i)) << '\n';
    }

    delete[] pa;
    return 0;

}
