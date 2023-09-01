#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char first[1001], second[1001], third[1001];
    cin >> first >> second >> third;

    int firstLen = strlen(first), thirdLen = strlen(third);

    if ('a' <= first[0] && first[0] <= 'z') first[0] = first[0] - 'a' + 'A';
    if ('a' <= second[0] && second[0] <= 'z') second[0] = second[0] - 'a' + 'A';

    for (int i = 1; i < firstLen; i++) {
        if ('A' <= first[i] && first[i] <= 'Z') first[i] = first[i] - 'A' + 'a';
    }

    for (int i = 0; i < thirdLen; i++) {
        if ('a' <= third[i] && third[i] <= 'z') third[i] = third[i] - 'a' + 'A';
    }
    cout << first << ' ' << second[0] << ". " << third;



    return 0;

}
