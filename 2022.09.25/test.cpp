#include<bits/stdc++.h>
using namespace std;
int main ()
{
    char a,b,c,d,e,f,g,h;
    string s;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> s;
    s.pop_back();

    int m1 = ((c - '0') * 10 + (d - '0')) + 60 * ((a - '0') * 10 + (b - '0'));
    int m2 = ((g - '0') * 10 + (h - '0')) + 60 * ((e - '0') * 10 + (f - '0'));
    int h1, m, br1 = 0, br2 = 0;
    cout << m1 << ' ' << m2 << endl;
    if (m2 < m1) m = m2 + 86400 - m1;
    else m = m2 - m1;
    h1 = m / 60;
    m = m % 60;
    cout << h1 << ' ' << m << endl;

    return 0;
}
