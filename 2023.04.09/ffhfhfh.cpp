#include <bits/stdc++.h>
using namespace std;

int main() {

    char a, b, c, d, e, f, g, h, i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    string first;
    first.push_back(a);
    first.push_back(e);
    first.push_back(i);

    string second;
    second.push_back(c);
    second.push_back(e);
    second.push_back(g);

    cout << stoi(first) * stoi(second) << endl;
    return 0;

}
