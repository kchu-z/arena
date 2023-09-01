#include <bits/stdc++.h>
using namespace std;

int main() {

    double sum = 0;

    for (int i = 1; i <= 10000; i++) sum += 1.0 / (i * i);

    cout << sqrt(sum * 6);
    return 0;

}
