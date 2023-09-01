#include <bits/stdc++.h>
using namespace std;

/*string multiplyTwoNumbers(string num1, string num2) {
   if (num1 == "0" || num2 == "0") {
      return "0";
   }
   string product(num1.size() + num2.size(), 0);
   for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
            int n = (num1[i] - '0') * (num2[j] - '0') + product[i + j + 1];
            product[i + j + 1] = n % 10;
            product[i + j] += n / 10;
      }
   }
   for (int i = 0; i < product.size(); i++) {
      product[i] += '0';
   }
   if (product[0] == '0') {
      return product.substr(1);
   }
   return product;
}
    int len1 = num1.Length;
    int len2 = num2.Length;
    if (len1 == 0 || len2 == 0)
        return "0";

    int []result = new int[len1 + len2];

    int i_n1 = 0;
    int i_n2 = 0;
    int i;

    for (i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
    i--;

    if (i == -1)
    return "0";

    string s = "";

    while (i >= 0) s += (result[i--]);

    return s;
}*/

string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string to(long long n, int base) {
    string s;

    while (n) {
        s.push_back(ch[n % base]);
        n /= base;
    }

    reverse(s.begin(), s.end());
    return s;
}

int getNum(char s) {
    if (isdigit(s)) return s - '0';
    return s - 'A' + 10;
}

long long from(string s, int base) {
    long long n = 0;

    for (char& i : s) n = n * base + getNum(i);

    //cout << s << ' ' << n;
    return n;
}

string tr(string s, int a, int b) {
    return to(from(s, a), b);
}

int main() {
    while (1) {
        int a, b;
        string s;
        cin >> s >> a >> b;

        cout << tr(s, a, b) << endl;
    }
    return 0;

}
