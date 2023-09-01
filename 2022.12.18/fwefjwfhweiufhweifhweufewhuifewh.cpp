#include <bits/stdc++.h>
using namespace std;

int get_next(int a, int b) {
    int m = (a * b) % 1000;

    if (a * b < 10) {
        if (m == 0) return 9;
        return m - 1;
    }

    int A = (a * b / 100 == 0) ? 0 : get_next(m / 100, 1), B = get_next(m / 10 % 10, 1), C = get_next(m % 10, 1);
    return 100 * A + 10 * B + C;
}

int findCurrentNumber(int previous, int previousAfter)
{
    if(previous==0 || previousAfter==0)
    {
        return 9;
    }

    int numberStruct=previous*previousAfter;
    int numberZ=0;
    int ten=1;

    while(numberStruct!=0)
    {
        int currentDigits=numberStruct%10;

        if(currentDigits==0)
        {
            currentDigits=9;
        }
        else
        {
            currentDigits--;
        }

        numberZ+=ten*currentDigits;
        ten*=10;
        numberStruct/=10;
    }

    int currentNumber=numberZ%1000;

    return currentNumber;
}

int main() {

    srand(time(0));

    int a, b;

    do {
        a = rand() % 1000;
        b = rand() % 1000;
    } while (get_next(a, b) == findCurrentNumber(a, b));

    cout << a << ' ' << b << endl;
    cout << get_next(a, b) << ' ' << findCurrentNumber(a, b);

    return 0;

}
