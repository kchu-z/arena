#include <bits/stdc++.h>
using namespace std;

bool isAdjacent(pair <int, int> a, pair <int, int> b) {
    int distanceX = abs(b.first - a.first), distanceY = abs(b.second - a.second);

    if (min(distanceX, distanceY) == 0 && max(distanceX, distanceY) == 1) return true;
    return false;
}

int main() {
 while(1){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << isAdjacent({a, b}, {c, d}) << endl;
}

    return 0;

}
