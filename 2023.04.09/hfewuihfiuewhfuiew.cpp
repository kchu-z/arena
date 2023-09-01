#include <bits/stdc++.h>
using namespace std;

vector <int> v(1);

void add(int idx) {
    if (idx <= 1 || v[idx] < v[idx / 2]) return;
    swap(v[idx], v[idx / 2]);

    add(idx / 2);
}

void rem() {
    int idx = v.size() - 1;
    if (idx == 0) return;

    swap(v[1], v[idx]);
    v.pop_back();

    idx = 1;

    while (1) {
        if (v.size() <= 2 * idx) break;
        int largest = 2 * idx;

        if (largest + 1 < v.size() && v[largest] < v[largest + 1]) largest++;
        if (v[largest] < v[idx]) break;

        swap(v[idx], v[largest]);
        idx = largest;
    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
        add(i);
    }

    for (int i = 1; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl << endl;

    for (int j = 1; j <= n; j++) {
        rem();

        for (int i = 1; i < v.size(); i++) cout << v[i] << ' ';
        cout << endl;
    }

    return 0;

}
