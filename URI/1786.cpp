#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    char d[10];
    int sz;
    while (gets(d)) {
        int b1 = 0, b2 = 0;
        rep(i, 0, 9) { b1 = (b1 + (d[i] - '0') * (i + 1)) % 11; }
        b1 %= 10;

        rep(i, 0, 9) { b2 = (b2 + (d[i] - '0') * (9 - i)) % 11; }
        b2 %= 10;

        rep(i, 0, 9) {
            if (i && i % 3 == 0)
                printf(".");
            printf("%c", d[i]);
        }
        printf("-");
        printf("%d%d\n", b1, b2);
    }
    return 0;
}
