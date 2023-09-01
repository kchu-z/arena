#include <bits/stdc++.h>
using namespace std;

struct Element{
    int a, b, c;

    Element(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
    }
};

int visited[100][100][100];
queue <Element> q;

Element tf(Element p) {
    if (p.a < p.b) return Element(2 * p.a, p.b - p.a, p.c);
    return Element(p.a - p.b, 2 * p.b, p.c);
}

int a, b, c;

void ex(Element previous, Element p) {
    if (visited[p.a][p.b][p.c]) return;
    visited[p.a][p.b][p.c] = visited[previous.a][previous.b][previous.c] + 1;

    q.push(p);

    if (max({p.a, p.b, p.c}) == a + b + c) {
        cout << visited[p.a][p.b][p.c] - 1 << endl;
        exit(0);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    q.push(Element{a, b, c});
    visited[a][b][c] = 1;

    while (q.size()) {
        Element p = q.front();

        ex(p, tf(Element(p.a, p.b, p.c)));
        ex(p, tf(Element(p.b, p.a, p.c)));
        ex(p, tf(Element(p.a, p.c, p.b)));
        ex(p, tf(Element(p.c, p.a, p.b)));
        ex(p, tf(Element(p.b, p.c, p.a)));
        ex(p, tf(Element(p.c, p.b, p.a)));

        q.pop();
    }

    cout << -1 << endl;
    return 0;

}

