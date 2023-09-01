#include <bits/stdc++.h>
using namespace std;

bitset <6000000> a;
int b[6000000], c[6000000];
int t[1000][1000];
int n, m, k;

long long XY_to_index(int x, int y) {
    long long distance_from_frame = min({x, y, n - x - 1, m - y - 1});
    //cout << distance_from_frame << ' ';

    long long total_sum = 0;
    long long current = 2 * (n + m) - 4;

    /**
    for (int i = 0; i < distance_from_frame; i++) {
        total_sum += current;
        current = (current - 8);
    }
    */

    total_sum = current * distance_from_frame - 4 * (distance_from_frame) * (distance_from_frame - 1);

    int N = n, M = m;
    N -= 2 * distance_from_frame;
    M -= 2 * distance_from_frame;

    x -= distance_from_frame;
    y -= distance_from_frame;

    //cout << x << ' ' << y << ' ' << N << ' ' << M << ' ' << total_sum << '\n';
    //return total_sum;

    if (x == 0) return total_sum + y;
    if (y == M - 1) return total_sum + (M - 1) + x;
    if (x == N - 1) return total_sum + (M - 1) + (N - 1) + (M - 1 - y);
    if (y == 0) return total_sum + 2 * (M - 1) + (N - 1) + (N - 1 - x);

    exit(-3);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool x;
            cin >> x;

            int idx = XY_to_index(i, j);
            a[idx] = x;
        }
    }

    int mx = 0;

    deque <pair <int, int>> q = {{0, -1}};

    for (int i = 1; i < n * m; i++) {
        if (a[i]) continue;
        if (q.)


        if (b[i] == 0 && i) b[i] = -1;
        if (a[i] == 0) mx = max(mx, c[i]);
    }

    cout << b[n * m - 1] << ' ' << mx << endl;
    return 0;

}
