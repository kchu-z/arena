#include <iostream>
using namespace std;

int check(int a, int b, int c) {
    if (a + b <= c || a + c <= b || b + c <= a) return false;
    return a + b + c;
}

int main() {

    int a, b, c, d, e, f, g, h, i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    int ans1 = check(a, b, c), ans2 = check(d, e, f), ans3 = check(g, h, i);

    if (ans1 == 0) cout << "NO\n";
    else cout << ans1 << '\n';
    if (ans2 == 0) cout << "NO\n";
    else cout << ans2 << '\n';
    if (ans3 == 0) cout << "NO\n";
    else cout << ans3 << '\n';

    return 0;

}
