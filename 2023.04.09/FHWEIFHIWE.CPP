#include <bits/stdc++.h>
using namespace std;

class Point{
public:
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


    return 0;

}


