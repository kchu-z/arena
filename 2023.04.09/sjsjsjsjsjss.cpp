#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <tuple>
using namespace std;
int main()
{
    long long n, d, br = 0;
    cin >> n >> d;

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    while (n % 2 == 0) {
        br++;
        n /= 2;
    }
    cout << br << endl;
    cout << ((br >= d) ? "YES" : "NO") << endl;
    return 0;
}
