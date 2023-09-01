#include <bits/stdc++.h>
using namespace std;

int maxdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void next_date(pair <pair <int, int>, int>& date) {
    int& day = date.first.first;
    int& month = date.first.second;
    int& year = date.second;

    if (day == 31 && month == 12) {
        day = 1;
        month = 1;
        year++;
    } else if (month == 2) {
        if (day == 29) {
            day = 1;
            month = month + 1;
        } else if (day == 28) {
            if (year % 4 == 0) day++;
            else {
                day = 1;
                month++;
            }
        } else day++;
    } else if (day == maxdays[month]) {
        day = 1;
        month++;
    } else day++;
}

int main() {

    int _dd, _mm, _yyyy, duration;
    char s;
    cin >> _dd >> s >> _mm >> s >> _yyyy >> duration;

    pair <pair <int, int>, int> current_date = {{1, 1}, 2019}, start_date = {{_dd, _mm}, _yyyy};
    int week_day = 2, br = 0;

    do {
        next_date(current_date);
        week_day = week_day % 7 + 1;
    } while (current_date != start_date);

    while (br < duration) {
        if (week_day <= 5) br++;
        next_date(current_date);
        week_day = week_day % 7 + 1;
    }

    do {
        next_date(current_date);
        week_day = week_day % 7 + 1;
    } while (week_day > 5);

    int day = current_date.first.first, month = current_date.first.second, year = current_date.second;

    if (day < 10) cout << '0';
    cout << day << '.';
    if (month < 10) cout << '0';
    cout << month << '.' << year << endl;

    return 0;

}
/// 01.01.2019 is Tuesday
