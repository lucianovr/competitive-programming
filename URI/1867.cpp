#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int getValue(char *s) {
    int val = 0, sum = 0;

    for (int i = 0; s[i]; ++i) {
        val += (s[i] - '0');
    }

    while (val >= 10) {
        sum = 0;
        while (val) {
            sum += val % 10;
            val /= 10;
        }
        val = sum;
    }
    return val;
}

int main() {
    char a[1000], b[1000];
    while (scanf("%s %s", a, b) == 2) {
        if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0)
            break;
        int A = getValue(a);
        int B = getValue(b);
        printf("%c\n", A > B ? '1' : (A < B ? '2' : '0'));
    }
    return 0;
}
