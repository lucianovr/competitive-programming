#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
typedef long long ll;
typedef pair<ll, ll> ii;

ll A[MAXN], lazy[4 * MAXN];
ii tree[4 * MAXN]; // (maior valor, idx)

int N;
ii neutro = ii(-1, -1);

inline ii combine(ii esq, ii dir) { return esq.first >= dir.first ? esq : dir; }

void build(int no = 1, int a = 0, int b = N - 1) {
    lazy[no] = 0;
    if (a == b) {
        tree[no] = ii(A[a], a);
        return;
    }
    int m = (a + b) / 2;
    int esq = 2 * no;
    int dir = esq + 1;
    build(esq, a, m);
    build(dir, m + 1, b);

    tree[no] = combine(tree[esq], tree[dir]);
}

inline void propagate(int no, int a, int b) {
    if (lazy[no] != 0) {
        tree[no].first += lazy[no];
        if (a != b) {
            lazy[2 * no] += lazy[no];
            lazy[2 * no + 1] += lazy[no];
        }
        lazy[no] = 0;
    }
}

void update(int i, int j, ll valor, int no = 1, int a = 0, int b = N - 1) {
    if (lazy[no])
        propagate(no, a, b);
    if (a > j || b < i)
        return;
    if (a >= i && b <= j) {
        lazy[no] += valor;
        propagate(no, a, b);
        return;
    }
    int m = (a + b) / 2;
    int esq = 2 * no;
    int dir = esq + 1;
    update(i, j, valor, esq, a, m);
    update(i, j, valor, dir, m + 1, b);
    tree[no] = combine(tree[esq], tree[dir]);
}

ii query(int i, int j, int no = 1, int a = 0, int b = N - 1) {
    if (lazy[no])
        propagate(no, a, b);
    if (a > j || b < i)
        return neutro;
    if (a >= i && b <= j)
        return tree[no];
    int m = (a + b) / 2;
    int esq = 2 * no;
    int dir = esq + 1;
    ii q1 = query(i, j, esq, a, m);
    ii q2 = query(i, j, dir, m + 1, b);

    if (q1.first == -1)
        return q2;
    if (q2.first == -1)
        return q1;
    return combine(q1, q2);
}

int main() {
    int Q, i, j, p;
    ll v;
    char op;

    while (scanf("%d %d", &N, &Q) != EOF) {
        for (int a = 0; a < N; ++a)
            scanf("%lld", &A[a]);

        build();

        while (Q--) {
            scanf(" %c %d %d", &op, &i, &j);
            i--, j--;
            if (op == 'C')
                printf("%lld\n", 1 + query(i, j).second);
            else {
                scanf("%lld", &v);
                update(i, j, v);
            }
        }
    }
    return 0;
}