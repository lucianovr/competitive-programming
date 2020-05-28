#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
typedef long long LL;

int A[MAXN];
pair<int, int> T[4 * MAXN];
int N; // #number of elements in A[]

pair<int, int> neutro = make_pair(-1, 1000000000);

pair<int, int> combine(pair<int, int> p1, pair<int, int> p2) {
    return make_pair(max(p1.first, p2.first), min(p1.second, p2.second));
}

void build(int no = 1, int a = 0, int b = N - 1) {
    if (a == b) {
        T[no] = make_pair(A[a], A[a]);
    } else {
        int m = (a + b) / 2;
        int esq = 2 * no;
        int dir = esq + 1;
        build(esq, a, m);
        build(dir, m + 1, b);
        T[no] = combine(T[esq], T[dir]);
    }
}
void update(int i, int v, int no = 1, int a = 0, int b = N - 1) {
    if (a > i || b < i)
        return;
    if (a == i && b == i) {
        A[i] = v;
        T[no] = make_pair(v, v);
        return;
    }
    int m = (a + b) / 2;
    int esq = 2 * no;
    int dir = esq + 1;
    update(i, v, esq, a, m);
    update(i, v, dir, m + 1, b);
    T[no] = combine(T[esq], T[dir]);
}
pair<int, int> query(int i, int j, int no = 1, int a = 0, int b = N - 1) {
    if (a > j || b < i)
        return neutro;
    if (a >= i && b <= j)
        return T[no];
    int m = (a + b) / 2;
    int esq = 2 * no;
    int dir = esq + 1;

    pair<int, int> p1 = query(i, j, esq, a, m);
    pair<int, int> p2 = query(i, j, dir, m + 1, b);
    return combine(p1, p2);
}

int main() {
    int Q, op, i, j, p;
    while (scanf("%d", &N) != EOF) {
        for (int a = 0; a < N; ++a) {
            scanf("%d", &A[a]);
        }
        build();
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d %d", &i, &p);
                update(i - 1, p);
            } else {
                scanf("%d %d", &i, &j);
                pair<int, int> ret = query(i - 1, j - 1);
                printf("%d\n", ret.first - ret.second);
            }
        }
    }
    return 0;
}
