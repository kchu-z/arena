#include <bits/stdc++.h>
using namespace std;

long long nok(long long a, long long b) {
    return a * b / __gcd(a, b);
}

int main() {

    long long total_tasks, hours, minutes_start, time_for_task, tasks_per_hour;
    cin >> total_tasks >> hours >> minutes_start >> time_for_task >> tasks_per_hour;
    minutes_start += hours * 60;

    long long minutes = minutes_start;
    long long lcm = nok(time_for_task, 60), decreased_tasks = lcm / time_for_task - lcm / 60 * tasks_per_hour;

    minutes += total_tasks / decreased_tasks * lcm;
    total_tasks %= decreased_tasks;

    while (total_tasks) {
        minutes++;

        if ((minutes - minutes_start) % time_for_task == 0) total_tasks--;
        if (minutes % 60 == 0 && total_tasks != 0) total_tasks += tasks_per_hour;
    }

    cout << minutes / (60 * 24) << ' ' << minutes / 60 % 24 << ' ' << minutes % 60 << endl;

    return 0;

}
