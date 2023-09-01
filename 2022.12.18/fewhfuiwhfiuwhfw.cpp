#include <bits/stdc++.h>
using namespace std;

int n, t, minimum = INT_MAX;
vector <int> next_elements;

bool m[1000001];

void get_elements(int num) {
    vector <int> digits;

    int num1 = num;

    while (num1) {
        digits.push_back(num1 % 10);
        num1 /= 10;
    }

    sort(digits.begin(), digits.end());

    for (int i = 0; i < digits.size(); i++) {
        if ((i + 1 == digits.size() || digits[i] != digits[i + 1]) && num + digits[i] <= n && !m[num + digits[i]]) {
            next_elements.push_back(num + digits[i]);

            m[next_elements.back()] = 1;

            if (next_elements.back() == n) {
                cout << t << endl;
                exit(0);
            }
        }
    }
}


int main() {

    cin >> n;
    vector <int> current_elements = {1};

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (t = 2; !current_elements.empty(); t++) {
        next_elements = {};
        for (int num : current_elements) get_elements(num);

        current_elements = next_elements;
    }

    cout << -1 << endl;
    return 0;

}
