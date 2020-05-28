#include <stdio.h>
#include <string.h>
#define rep(i, a, b) for (int i = a; i < b; i++)

int main() {
    int t, n, m, query, ans, k, wlen;
    char s[55][55], w[55];

    scanf("%d", &t);
    while (t--) {

        scanf("%d%d\n", &n, &m);
        rep(i, 0, n) gets(s[i]);

        scanf("%d\n", &query);
        while (query--) {
            scanf(" %s", w);
            wlen = strlen(w);

            ans = 0;
            rep(i, 0, n) {
                rep(j, 0, m) {
                    if (m - j >= wlen && wlen > 1) {
                        for (k = 0; k < wlen; k++) // horizontal
                            if (w[k] != s[i][k + j])
                                break;
                        if (k == wlen)
                            ans++;
                    }
                    if (n - i >= wlen) {
                        for (k = 0; k < wlen; k++)
                            if (w[k] != s[k + i][j])
                                break;
                        if (k == wlen)
                            ans++;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}