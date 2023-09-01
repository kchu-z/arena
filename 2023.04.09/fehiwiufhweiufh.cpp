#include <bits/stdc++.h>
using namespace std;

class Point{
    double x, y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double x, double y) {
        this -> x = x;
        this -> y = y;
    }

    void read() {
        cin >> x >> y;
    }
};

class Line{
    double a, b, c;
    cin >> a >> b >> c;

    Line(Point a, Point b) {
        this -> a = a.y + b.y;
        this -> b = a.x + b.x;

        this -> c = a.x * b.y - a.y * b.x;
    }

    void read() {
        Point a, b;
        a.read();
        b.read();

        this -> a = a.y + b.y;
        this -> b = a.x + b.x;

        this -> c = a.x * b.y - a.y * b.x;
    }

    bool execute(Point u) {
        double x = a * u.x + b * u.y + c;
    }
};

class Triangle{
    Point a, b, c;

    Triangle() {}

    Triangle(Point a, Point b, Point c) {
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }

    void read() {
        a.read();
        b.read();
        c.read();
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    return 0;

}
