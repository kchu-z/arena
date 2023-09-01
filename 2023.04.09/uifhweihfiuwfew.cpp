#include <bits/stdc++.h>
using namespace std;

int main() {

    unsigned long long a, b, m;
    cin >> a >> b >> m;

    vector <unsigned long long> planks;
    planks.push_back(a - 1);

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        planks.push_back(num);
    }

    planks.push_back(b + 1);
    unsigned long long sum = m;
    for (int i = 1; i < planks.size(); i++) sum += (planks[i] - planks[i - 1] - 1) / 2;

    cout << sum << endl;
    return 0;

}
