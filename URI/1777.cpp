#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";
#define F first
#define S second
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vii v, newV;

int main() {
    int t, n, c, caso = 1;
    scanf("%d", &t);
    while (t--) {
        v.clear();
        scanf("%d %d", &n, &c);
        int a, b;
        rep(i, 0, c) {
            scanf("%d %d", &a, &b);
            v.pb(ii(a, b));
        }
        sort(v.begin(), v.end());
        int last = 0, size = 1;

        for (int i = 1; i < c; i++) {
            if (v[i].F <= v[last].S) {
                v[last].S = max(v[last].S, v[i].S);
            } else {
                last++;
                v[last] = v[i];
                size++;
            }
        }

        int query;
        scanf("%d", &query);
        int cont = 0;
        while (query--) {
            scanf("%d", &a);

            bool ok = false;
            int lo = 0, hi = size - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (a >= v[mid].first && a <= v[mid].second) {
                    ok = true;
                    break;
                } else if (a < v[mid].first)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            if (ok)
                cont++;
        }

        printf("Caso #%d: %d\n", caso++, cont);
    }
    return 0;
}
