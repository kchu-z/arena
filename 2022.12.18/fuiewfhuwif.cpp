#include <bits/stdc++.h>
using namespace std;

int passengers, weight, br = 0;

long long power(int k) {
    if (k == 0) return 1;
    return 2 * power(k - 1);
}

void check(vector <int>& v) {
    int mx = power(v.size()), elev_passenger = 0, elev_weight = 0, mx_passengers = 0;
    vector <int> passengers_to_remove;

    for (int i = 0; i < mx; i++) {
        int k = i, current_br = 0;
        vector <int> current_passengers_to_remove;

        for (int j = 0; j < v.size(); j++) {
            if (k % 2) {
                elev_passenger++;
                elev_weight += v[j];

                current_br++;
                current_passengers_to_remove.push_back(v[j]);
            }

            k /= 2;
        }

        if (elev_passenger <= passengers && elev_weight <= weight) {
            if (mx_passengers < current_br) {
                mx_passengers = current_br;
                passengers_to_remove = current_passengers_to_remove;
            }
        }
    }

    vector <int> new_arr;

    for (int i : passengers_to_remove) {
        for (int j = 0; j < v.size(); j++) {
            if (i != v[j]) {
                int idx = j;

                v[j] = 0;
                break;
            }
        }
    }

    for (int i : v) {
        if (i != 0) new_arr.push_back(i);
    }

    v = new_arr;
}

int main() {

    cin >> passengers >> weight;
    vector <int> v(4);

    for (int i = 0; i < 4; i++) cin >> v[i];

    do {
        br++;
        check(v);
    } while (v.size() != 0);

    cout << br << endl;
    return 0;

}
