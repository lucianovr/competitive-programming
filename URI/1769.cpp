#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    char s[20];
    int num[20], d1, d2, n1, n2;

    while (gets(s)) {
        num[1] = s[0] - '0';
        num[2] = s[1] - '0';
        num[3] = s[2] - '0';
        num[4] = s[4] - '0';
        num[5] = s[5] - '0';
        num[6] = s[6] - '0';
        num[7] = s[8] - '0';
        num[8] = s[9] - '0';
        num[9] = s[10] - '0';

        // rep(i,1,10) cout << num[i]; cout << "\n";

        d1 = s[12] - '0';
        d2 = s[13] - '0';

        // cout << d1 << " " << d2 << "\n";

        n1 = n2 = 0;

        for (int i = 1; i <= 9; i++) {
            n1 = (n1 + num[i] * i);
        }
        n1 %= 11;
        n1 %= 10;

        for (int i = 1; i <= 9; i++) {
            n2 = (n2 + num[i] * (10 - i));
        }
        n2 %= 11;
        n2 %= 10;

        //	cout << n1 << " " << n2 << "\n";
        if (n1 == d1 && n2 == d2)
            printf("CPF valido\n");
        else
            printf("CPF invalido\n");
    }
    return 0;
}
