#include <bits/stdc++.h>
using namespace std;

int main() {

    vector <pair <int, int>> delta{{0, 1}, {1, 0}, {1, 1}};

    vector <pair <int, int>> current_cells{{0, 0}};
    map <pair <int, int>, bool> passed, restore;

    cout << "(0; 0)\n";

    for (int t = 1; t <= 16; t++) {
        vector <pair <int, int>> next_cells;

        for (auto p : current_cells) {
            for (auto dir : delta) {
                pair <int, int> cell = {p.first + dir.first, p.second + dir.second};

                if (!passed[cell]) {
                    passed[cell] = 1;

                    next_cells.push_back(cell);
                }
            }
        }

        for (auto p : next_cells) cout << '(' << p.first << "; " << p.second << "), ";
        cout << "\b\b; \n";

        current_cells = next_cells;
        passed = restore;
    }

    return 0;

}
