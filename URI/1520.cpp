#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
vi v;
int bs(int k, int x) {
    int ini = 0, fim = k, me;

    while (ini <= fim) {
        me = (ini + fim) / 2;
        if (v[me] == x)
            return me;
        else if (v[me] < x)
            ini = me + 1;
        else
            fim = me - 1;
    }
    return -1;
}

int main() {
    int x, y, a, b, n;
    while (scanf("%d", &n) != EOF) {
        v.clear();
        rep(i, n) {
            scanf("%d%d", &x, &y);
            for (int k = x; k <= y; k++)
                v.pb(k);
        }
        sort(all(v));
        int k = v.sz - 1;
        cin >> x;
        int ret = bs(k, x);
        if (ret == -1)
            printf("%d not found\n", x);
        else {
            a = ret;
            b = ret;

            while (a >= 0 && v[a] == x)
                a--;
            while (b <= k && v[b] == x)
                b++;

            printf("%d found from %d to %d\n", x, a + 1, b - 1);
        }
    }
    return 0;
}
