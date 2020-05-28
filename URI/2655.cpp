#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
typedef long long LL;

LL A[MAXN], T[4 * MAXN];
int N;
int neutro = 0;

LL combine(LL Left, LL Right) { return Left | Right; }

void build(int no = 1, int a = 0, int b = N - 1) {
    if (a == b) {
        T[no] = A[a];
    } else {
        int m = (a + b) / 2;
        int esq = 2 * no;
        int dir = esq + 1;
        build(esq, a, m);
        build(dir, m + 1, b);
        T[no] = combine(T[esq], T[dir]);
    }
}

void update(int pos, LL valor, int no = 1, int a = 0, int b = N - 1) {
    if (a > pos || b < pos)
        return;
    if (a == b && a == pos) {
        T[no] ^= valor;
        return;
    }
    int m = (a + b) / 2;
    int esq = 2 * no;
    int dir = esq + 1;
    update(pos, valor, esq, a, m);
    update(pos, valor, dir, m + 1, b);
    T[no] = combine(T[esq], T[dir]);
}

LL query(int i, int j, int no = 1, int a = 0, int b = N - 1) {
    if (a > j || b < i)
        return neutro;
    if (a >= i && b <= j)
        return T[no];
    int m = (a + b) / 2;
    int esq = 2 * no;
    int dir = esq + 1;

    LL Left = query(i, j, esq, a, m);
    LL Right = query(i, j, dir, m + 1, b);
    return combine(Left, Right);
}

int main() {
    int Q, M;
    int monster, op, a, b;

    while (scanf("%d %d %d", &N, &Q, &M) == 3) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", &monster);
            A[i] = (1LL << monster);
        }
        build();
        while (Q--) {
            scanf("%d %d %d", &op, &a, &b);
            if (op == 1) {
                LL ret = query(a - 1, b - 1);
                cout << __builtin_popcountll(ret) << "\n";
            } else {
                update(a - 1, A[a - 1] ^ (1LL << b));
                A[a - 1] = (1LL << b);
            }
        }
    }
    return 0;
}
