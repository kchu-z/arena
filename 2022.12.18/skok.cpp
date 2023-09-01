#include <bits/stdc++.h>
using namespace std;

int main() {

    int a, b, m;
    cin >> a >> b >> m;

    vector <int> planks;
    planks.push_back(a - 1);

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        planks.push_back(num);
    }

    planks.push_back(b + 1);

    string sum = to_string(m);
    reverse(sum.begin(), sum.end());

    for (int i = 1; i < planks.size(); i++) {
        string str = to_string((planks[i] - planks[i - 1] - 1) / 2);
        reverse(str.begin(), str.end());


    }

    cout << sum << endl;
    return 0;

}
