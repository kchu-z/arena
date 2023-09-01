#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> a(n + 1), b(n + 1), t(m);
    vector <pair <int, int>> v(m);

    for (int i = 0; i < m; i++) {
        char s;

        cin >> v[i].first >> s;

        if (s == 'u' || s == 'd') v[i].second = 0;
        else if (s == 'l') v[i].second = 1;
        else v[i].second = -1;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        int pos = v[i].first, dir = v[i].second;
        int pos_copy = n - pos + 1, dir_copy = -dir;

        int tm;

        if (dir == 1) {
            if (a[pos - 1] < 1) {
                pos = max(0, pos - 1);
                if (pos) a[pos] = 1;

                if (a[pos - 1] < 2) {
                    pos = max(0, pos - 1);
                    if (pos) a[pos] = 2;
                }
            } else if (a[pos - 1] < 2) {
                pos = max(0, pos - 1);
                if (pos) a[pos] = 2;
            }

            tm = pos + 2;
        } else if (dir == 0) {
            if (a[pos - 1] < 2) {
                pos = max(0, pos - 1);
                if (pos) a[pos] = 2;
            }

            tm = pos + 2;
        } else if (dir == -1) {
            tm = pos + 2;
        }

        if (t[i] == 0) t[i] = tm;
        else t[i] = min(t[i], tm);

        v[i].first = pos_copy;
        v[i].second = dir_copy;
    }

    for (int i = m - 1; i >= 0; i--) {
        int pos = v[i].first, dir = v[i].second;
        int pos_copy = n - pos + 1, dir_copy = -dir;

        int tm;

        if (dir == 1) {
            if (b[pos - 1] < 1) {
                pos = max(0, pos - 1);
                if (pos) b[pos] = 1;

                if (b[pos - 1] < 2) {
                    pos = max(0, pos - 1);
                    if (pos) b[pos] = 2;
                }
            } else if (b[pos - 1] < 2) {
                pos = max(0, pos - 1);
                if (pos) b[pos] = 2;
            }

            tm = pos + 2;
        } else if (dir == 0) {
            if (b[pos - 1] < 2) {
                pos = max(0, pos - 1);
                if (pos) b[pos] = 2;
            }

            tm = pos + 2;
        } else if (dir == -1) {
            tm = pos + 2;
        }

        if (t[i] == 0) t[i] = tm;
        else t[i] = min(t[i], tm);

        v[i].first = pos_copy;
        v[i].second = dir_copy;
    }

    int mx = 0;

    for (int i = 0; i < m; i++) {
        mx = max(mx, t[i]);
        cout << t[i] << ' ';
    }

    cout << endl;
    cout << mx << endl;
    return 0;

}

