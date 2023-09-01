#include <bits/stdc++.h>
using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char a,b,c,d,e,f,g,h;
    string s;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> s;
    s.pop_back();

    int m1 = ((c - '0') * 10 + (d - '0')) + 60 * ((a - '0') * 10 + (b - '0'));
    int m2 = ((g - '0') * 10 + (h - '0')) + 60 * ((e - '0') * 10 + (f - '0'));
    int h1, m, br1 = 0, br2 = 0;
    if (m2 < m1) m = m2 + 1440 - m1;
    else m = m2 - m1;
    h1 = m / 60;
    m = m % 60;
    cout << h1 << ' ' << m << endl;

    for (int i = 0; i < s.size(); i++) {
        int br = 0;
        if (s[i + 1] >= 'a' && s[i + 1] <= 'z') {
            i++;
            if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                i++;
                br += s[i] - '0';
                if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    i++;
                    br = br * 10 + s[i] - '0';
                }
            }
            if (br == 0) br++;
            br2 += br;
        } else {
            if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                i++;
                br += s[i] - '0';
                if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    i++;
                    br = br * 10 + s[i] - '0';
                }
            }
            if (br == 0) br++;
            br1 += br;
        }
    }

    cout << br1 << ' ' << br2;

    return 0;

}
