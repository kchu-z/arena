#include <bits/stdc++.h>
using namespace std;

struct Point{
    long long x, y;

    Point(long long a, long long b) {
        x = a;
        y = b;
    }

    Point() {

    }

    void read() {
        cin >> x >> y;
    }
};

long long man(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool is_crossing(Point a, Point b, Point c, Point d) {
    if (a.x == b.x && c.y == d.y) {
        return (min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y))
        && (min(c.x, d.x) <= a.x && a.x <= max(c.x, d.x));
    } else if (a.y == b.y && c.x == d.x) {
        return (min(c.y, d.y) <= a.y && a.y <= max(c.y, d.y))
        && (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x));
    }

    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Point a, b, c, d;
    a.read();
    b.read();
    c.read();
    d.read();

    long long ans = 0;

    if (a.x == b.x && c.x == d.x) {
        if (max(a.y, b.y) < min(c.y, d.y)) {
            ans = min(c.y, d.y) - max(a.y, b.y) + abs(a.x - c.x);
        } else if (max(d.y, c.y) < min(a.y, b.y)) {
            ans = min(a.y, b.y) - max(c.y, d.y) + abs(c.x - a.x);
        } else {
            ans = abs(a.x - c.x);
        }
    } else if (a.y == b.y && c.y == b.y) {
        if (max(a.x, b.x) < min(c.x, d.x)) {
            ans = min(c.x, d.x) - max(a.x, b.x) + abs(a.y - c.y);
        } else if (max(d.x, c.x) < min(a.x, b.x)) {
            ans = min(a.x, b.x) - max(c.x, d.x) + abs(c.y - a.y);
        } else {
            ans = abs(a.y - c.y);
        }
    } else if (a.x == b.x && c.y == d.y) {
        if (min(a.y, b.y) < c.y && c.y < max(a.y, b.y)) {
            ans = min(abs(c.x - a.x), abs(d.x - a.x));
        } else if (min(c.x, d.x) < a.x && a.x < max(c.x, d.x)) {
            ans = min(abs(a.y - c.y), abs(b.y - c.y));
        } else ans = min({ man(a, c), man(a, d), man(b, c), man(b, d) });
    } else if (a.y == b.y && c.x == d.x) {
        if (min(a.x, b.x) < c.x && c.x < max(a.x, b.x)) {
            ans = min(abs(c.y - a.y), abs(d.y - a.y));
        } else if (min(c.y, d.y) < a.y && a.y < max(c.y, d.y)) {
            ans = min(abs(a.x - c.x), abs(b.x - c.x));
        } else ans = min({ man(a, c), man(a, d), man(b, c), man(b, d) });
    }

    if (is_crossing(a, b, c, d)) {
        ans = 0;
    }

    cout << ans << endl;
    return 0;

}
