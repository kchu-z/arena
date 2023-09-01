#include <bits/stdc++.h>
using namespace std;

class Bitset
{
private:
    int size, offset;

    unsigned long long* arr;
public:

    Bitset(int x)
    {
        size = x;
        arr = new unsigned long long[x >> 6 + 1];

        offset = 0;
    }

    ~Bitset()
    {
        delete arr;
    }

    void insert(int);
    void erase(int);

    bool find(int);

    void operator<<(int pos)
    {
        offset += pos;
    };

    void operator>>(int pos)
    {
        offset -= pos;
    }
};

void Bitset::insert(int pos)
{
    pos += offset;

    arr[pos >> 6] |= (1 << (pos % 64));
}

void Bitset::erase(int pos)
{
    pos += offset;

    arr[pos >> 6] &= (ULLONG_MAX ^ (1 << pos));
}

bool Bitset::find(int pos)
{
    pos += offset;

    return arr[pos >> 6] & (1 << pos);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Bitset p(1000001);

    for (int i = 0; i < n - 2; i++)
    {
        int x;
        cin >> x;

        p.insert(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (p.find(i) == 0)
        {
            cout << i << ' ';
        }
    }


    return 0;

}
