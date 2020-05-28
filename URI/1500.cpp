#include <cstdio>
#include <cstring>

long long segtree[400000], lazy[400000];

void propagate(int root, int l, int r) {
    segtree[root] += lazy[root] * (r - l + 1);
    if (l != r) {
        lazy[2 * root + 1] += lazy[root];
        lazy[2 * root + 2] += lazy[root];
    }
    lazy[root] = 0;
}

long long query(int root, int l, int r, int a, int b) {
    if (l > b || r < a)
        return 0;

    propagate(root, l, r);
    if (l >= a && r <= b)
        return segtree[root];

    int mid = (l + r) / 2;
    return query(2 * root + 1, l, mid, a, b) + query(2 * root + 2, mid + 1, r, a, b);
}

void update(int root, int l, int r, int a, int b, int val) {
    if (l > b || r < a)
        return;
    if (l >= a && r <= b) {
        lazy[root] += val;
        return;
    }

    int mid = (l + r) >> 1;
    update(2 * root + 1, l, mid, a, b, val);
    update(2 * root + 2, mid + 1, r, a, b, val);

    propagate(2 * root + 1, l, mid);
    propagate(2 * root + 2, mid + 1, r);
    segtree[root] = segtree[2 * root + 1] + segtree[2 * root + 2];
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, c, op, p, q, v;
        scanf("%d %d", &n, &c);

        int hi = 1;
        while (hi < n)
            hi <<= 1;
        hi <<= 1;

        for (int i = 0; i < hi; i++)
            segtree[i] = lazy[i] = 0;

        while (c--) {
            scanf("%d %d %d", &op, &p, &q);
            if (op == 0) {
                scanf("%d", &v);
                update(0, 0, n - 1, p - 1, q - 1, v);
            } else
                printf("%lld\n", query(0, 0, n - 1, p - 1, q - 1));
        }
    }
}