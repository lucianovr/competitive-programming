#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define contains(s, x) (s.find(x) != s.end())

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {

    int n;
    char h1, h0;

    while (scanf("%d", &n) == 1) {

        string ans;
        while (n--) {
            int v = 0;
            scanf(" %c%c", &h1, &h0);
            if ('0' <= h1 && h1 <= '9')
                v = 16 * (h1 - '0');
            else if (h1 >= 'A' && h1 <= 'Z')
                v = 16 * (10 + (h1 - 'A'));
            else
                v = 16 * (10 + (h1 - 'a'));

            if ('0' <= h0 && h0 <= '9')
                v += (h0 - '0');
            else if (h0 >= 'A' && h0 <= 'Z')
                v += (10 + (h0 - 'A'));
            else
                v += (10 + (h0 - 'a'));

            ans += char(v);
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
