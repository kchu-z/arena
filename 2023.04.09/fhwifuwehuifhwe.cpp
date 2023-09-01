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

class Circle{
public:
    Point k;
    double r;

    Circle(Point a, double b) {
        k = a;
        r = b;
    }

    Circle(double b) {
        k = Point(0, 0);
        r = b;
    }

    bool InnerPoint(Point u) {
        double z = (u.x - k.x) * (u.x - k.x) + (u.y - k.y) * (u.y - k.y);
        return z <= r * r;
    }
};

class Square{
public:
    Point k;
    double r;

    Square(Point a, double b) {
        k = a;
        r = b;
    }

    Square(double b) {
        k = Point(0, 0);
        r = b;
    }

    bool InnerPoint(Point u) {
        return max(abs(u.x), abs(u.y)) <= r;
    }
};

long long br = 0;

int main() {

    int n;
    double side;

    cin >> n >> side;
    side /= 2;

    Square square(side);
    Circle a(side), b(side * 2 / 3), c(side / 3);

    for (int i = 0; i < n; i++) {
        Point u;
        u.read();

        if (square.InnerPoint(u)) br++;
        if (a.InnerPoint(u)) br += 4;
        if (b.InnerPoint(u)) br += 5;
        if (c.InnerPoint(u)) br += 5;
        if (u.x == 0 && u.y == 0) br += 5;
    }

    cout << br << endl;
    return 0;

}

