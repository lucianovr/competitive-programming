#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
typedef pair<int, int> ii;
typedef long long ll;

const int mod = 9;
const int MAXN = 4 * 100001;

struct T {
    int maior;
    int freq[9];
    T() {
        maior = -1;
        memset(freq, 0, sizeof freq);
    }
};

struct T neutral;

struct T tree[MAXN];
int lazy[MAXN];
int v[9]; // aux
int N, Q, A, B;

void build_tree(int no = 1, int a = 0, int b = N - 1) {
    lazy[no] = 0;
    if (a == b) {
        for (int i = 0; i < 9; ++i)
            tree[no].freq[i] = 0;
        tree[no].freq[1] = 1;
        tree[no].maior = 1;
        return;
    }
    int m = (a + b) / 2;
    int e = no << 1;
    int d = e + 1;

    build_tree(e, a, m);
    build_tree(d, m + 1, b);
    rep(i, 0, 9) tree[no].freq[i] = tree[e].freq[i] + tree[d].freq[i];
    tree[no].maior = 1;
}

void propagate(int no, int a, int b) {
    if (lazy[no]) {
        int x = lazy[no], maior = 0, aux = 0;
        rep(i, 0, 9) v[(i + x) % mod] = tree[no].freq[i];
        rep(i, 0, 9) {
            tree[no].freq[i] = v[i];
            if (v[i] >= aux)
                aux = v[i], maior = i;
            v[i] = 0;
        }
        tree[no].maior = maior;
        if (a != b) {
            lazy[2 * no] += lazy[no];
            lazy[2 * no + 1] += lazy[no];
        }
        lazy[no] = 0;
    }
}

void update(int no, int a, int b, int i, int j, int value) {
    if (lazy[no])
        propagate(no, a, b);
    if (a > j || b < i)
        return;
    if (a >= i && b <= j) {
        lazy[no] = (lazy[no] + value) % mod;
        if (lazy[no])
            propagate(no, a, b);
        return;
    }
    int m = (a + b) / 2;
    int e = no << 1;
    int d = e + 1;

    update(e, a, m, i, j, value);
    update(d, m + 1, b, i, j, value);
    int aux = 0, maior = 0;
    rep(i, 0, 9) {
        tree[no].freq[i] = tree[e].freq[i] + tree[d].freq[i];
        if (tree[no].freq[i] >= aux)
            aux = tree[no].freq[i], maior = i;
    }
    tree[no].maior = maior;
}

struct T query(int no, int a, int b, int i, int j) {
    if (a > j || b < i)
        return neutral;

    if (lazy[no])
        propagate(no, a, b);
    if (a >= i && b <= j)
        return tree[no];

    int m = (a + b) >> 1;
    struct T q1 = query(no << 1, a, m, i, j);
    struct T q2 = query((no << 1) + 1, m + 1, b, i, j);

    struct T v;
    int aux = -1, maior = -1;
    rep(i, 0, 9) {
        v.freq[i] = q1.freq[i] + q2.freq[i];
        if (v.freq[i] >= aux)
            aux = v.freq[i], maior = i;
    }
    v.maior = maior;
    return v;
}

int resp[100001 + 10];
void getans(int no = 1, int a = 0, int b = N - 1) {
    if (lazy[no])
        propagate(no, a, b);
    if (a == b) {
        resp[a] = tree[no].maior;
        return;
    }
    int m = (a + b) / 2;
    getans(2 * no, a, m);
    getans(2 * no + 1, m + 1, b);
}

int main() {
    scanf("%d %d", &N, &Q);
    build_tree();
    int maior;
    while (Q--) {
        scanf("%d %d", &A, &B);
        maior = query(1, 0, N - 1, A, B).maior;
        update(1, 0, N - 1, A, B, maior);
    }
    getans();
    rep(i, 0, N) printf("%d\n", resp[i]);
    return 0;
}