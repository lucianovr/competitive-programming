#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int main() {
    int n, caso = 1, x;
    char letra[100], temp;

    while (scanf("%d", &n) && n) {

        for (int i = 'A'; i <= 'Z'; i++)
            letra[i - 'A' + 1] = i;

        printf("Instancia %d\n", caso++);
        rep(i, 0, n) {
            scanf("%d", &x);
            printf("%c", letra[x]);
            temp = letra[x];
            for (int j = x; j >= 2; j--)
                letra[j] = letra[j - 1];
            letra[1] = temp;
        }
        printf("\n\n");
    }
    return 0;
}
