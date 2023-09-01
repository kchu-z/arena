#include <bits/stdc++.h>
using namespace std;

bool check(pair <int, int> p, int l, int r) {
    return l < p.first && p.second < r;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, br = 0;
    cin >> n >> q;

    vector <pair <int, int>> minHeight;
    vector <pair <int, int>> boards;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (minHeight.size() && minHeight.back().second < num) {
            minHeight.pop_back();
        }

        if (minHeight.size() && minHeight.back().second == num) {
            int left = minHeight.back().first, right = i;
            bool f = false;

            if (boards.size() && check(boards.back(), left, right)) {
                br++;
                f = true;
            }

            if (!f) boards.push_back({left, right});
        }

        minHeight.push_back({i, num});

        //for (auto p : boards) cout << "{" << p.first + 1 << ", " << p.second + 1 << "}, ";
        //cout << "\b\b  \n";
    }

    if (q == 1) cout << br + boards.size() << endl;
    else cout << br << endl;
    return 0;

}
