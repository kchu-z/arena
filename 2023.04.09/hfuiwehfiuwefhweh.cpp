#include <bits/stdc++.h>
using namespace std;

bool is_opening(char s) {
    return s == '(' || s == '[' || s == '{';
}

int main() {

    string str;
    cin >> str;

    int ans = 0;
    stack <int> round, square, curly;

    for (int i = 0; i < str.size(); i++) {
        char s = str[i];

        if (is_opening(s)) {
            if (s == '(') round.push(i);
            else if (s == '[') square.push(i);
            else if (s == '{') curly.push(i);
        } else {
            if (s == ')') {

                if (round.empty()) {
                    ans++;
                    continue;
                }

                int left = round.top();

                while (square.size() && left < square.top()) {
                    ans++;
                    square.pop();
                }

                while (curly.size() && left < curly.top()) {
                    ans++;
                    curly.pop();
                }

                round.pop();
            } else if (s == ']') {

                if (square.empty()) {
                    ans++;
                    continue;
                }

                int left = square.top();

                while (round.size() && left < round.top()) {
                    ans++;
                    round.pop();
                }

                while (curly.size() && left < curly.top()) {
                    ans++;
                    curly.pop();
                }

                square.pop();
            } else if (s == '}') {

                if (curly.empty()) {
                    ans++;
                    continue;
                }

                int left = curly.top();

                while (square.size() && left < square.top()) {
                    ans++;
                    square.pop();
                }

                while (round.size() && left < round.top()) {
                    ans++;
                    round.pop();
                }

                curly.pop();
            }
        }
    }

    cout << ans + round.size() + square.size() + curly.size() << endl;
    return 0;

}
/// {([(])]()]
///
