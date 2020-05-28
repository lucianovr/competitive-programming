#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int pai[65], ans;

struct edge {
    int A, B, C;
    edge(int A = 0, int B = 0, int C = 0) : A(A), B(B), C(C){};
} e[210];

bool comp(edge E1, edge E2) { return E1.C < E2.C; }

int find(int i) {
    if (i != pai[i])
        pai[i] = find(pai[i]);
    return pai[i];
}

void join(int a, int b, int c) {
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    pai[b] = a;
    ans += c;
}

int main() {
    int r, c, v, w, p;

    while (scanf("%d %d", &r, &c) != EOF) {
        rep(i, 1, r + 1) pai[i] = i;
        rep(i, 0, c) {
            scanf("%d %d %d", &v, &w, &p);
            e[i] = edge(v, w, p);
        }

        sort(e, e + c, comp);

        ans = 0;
        rep(i, 0, c) { join(e[i].A, e[i].B, e[i].C); }
        printf("%d\n", ans);
    }
    return 0;
}
