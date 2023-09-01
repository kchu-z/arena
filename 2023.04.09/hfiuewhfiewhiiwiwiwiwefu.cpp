#include <bits/stdc++.h>
using namespace std;

unordered_map <char, int> prior{
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3},
    {'(', -1},
    {')', 0},

};

int ex(int a, int b, char c) {
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '^') return (int) pow(a, b);

    exit(1);
}

int main() {

    string s;
    getline(cin, s);
    s.push_back('+');

    bool isLastNumber = false;

    stack <int> nums;
    stack <char> op;

    for (char c : s) {
        if (isdigit(c)) {
            if (isLastNumber) {
                nums.top() *= 10;
                nums.top() += c - '0';

                continue;
            }

            nums.push(c - '0');
            isLastNumber = true;
        } else {
            isLastNumber = false;
            if (c == '(') {
                op.push('(');
                continue;
            }

            while (op.size() && prior[op.top()] >= prior[c]) {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();

                nums.push(ex(first, second, op.top()));
                op.pop();
            }

            if (c != ')') {
                op.push(c);
            } else op.pop();
        }
    }

    cout << nums.top() << endl;
    return 0;

}
