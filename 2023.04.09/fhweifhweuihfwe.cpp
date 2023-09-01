#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double u, double v) {
        x = u;
        y = v;
    }

    void read() {
        cin >> x >> y;
    }
};

bool is_straight_line(Point a, Point b, Point c) {
    int x1 = b.x - a.x;
    int y1 = b.y - a.y;
    int x2 = c.x - a.x;
    int y2 = c.y - a.y;

    return x1 * y2 == y1 * x2;
}

int main() {

    Point a, b, c;
    a.read();
    b.read();
    c.read();

    cout << is_straight_line(a, b, c);


    return 0;

}


