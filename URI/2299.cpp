#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)

// 23;55

int pd[1005][55], N;
int val[55], num[55];

int mochila(int s, int i) {
    if (i == N)
        return 0;
    if (pd[s][i] != -1)
        return pd[s][i];

    int ret = mochila(s, i + 1);

    if (s - val[i] >= 0)
        ret = max(ret, num[i] + mochila(s - val[i], i + 1));

    return pd[s][i] = ret;
}

int main() {
    int S, t = 0;
    while (scanf("%d %d", &S, &N) == 2) {
        if (S == 0 && N == 0)
            break;

        rep(i, 0, N) { scanf("%d %d", &val[i], &num[i]); }
        memset(pd, -1, sizeof pd);
        printf("Teste %d\n%d\n\n", ++t, mochila(S, 0));
    }
    return 0;
}
