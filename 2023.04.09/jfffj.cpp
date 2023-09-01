#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve(int arr[]) {
    cout << arr[0] * k;

    for (int i = 1; i < n; i++) cout << ' ' << arr[i];
    cout << endl;
}

int main() {

    cin >> n >> k;

    static int first[50], second[50], third[50];

    for (int i = 0; i < n; i++) cin >> first[i];
    for (int i = 0; i < n; i++) cin >> second[i];
    for (int i = 0; i < n; i++) cin >> third[i];

    solve(first);
    solve(second);
    solve(third);

    return 0;

}
