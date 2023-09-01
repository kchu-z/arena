#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;

    void read() {
        cin >> x >> y;
    }
};

struct Line{
    double a, b, c;

    Line(Point u, Point v) {
        a = u.y - v.y;
        b = v.x - u.x;
        c = u.x * v.y - u.y * v.x;
    }

    int execute(Point u) {
        double g = u.x * a + u.y * b + c;

        if (g == 0) return 0;
        if (g > 0) return 1;
        return -1;
    }
};

int main() {

    Point a, b, d;
    a.read();
    b.read();
    d.read();

    Line p(a, b);

    cout << p.execute(d);
    return 0;

}
