#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

#define MAXN 100000 + 5
struct tree {
    long long h, e, r;
    tree(long long h = 0, long long e = 0, long long r = 0) : h(h), e(e), r(r) {}
    tree operator+(tree t) { return tree(h + t.h, e + t.e, r + t.r); }
    void shift() {
        long long temp = r;
        r = e;
        e = h;
        h = temp;
    }
};

tree M[4 * MAXN];
long long lazy[4 * MAXN];

void build(int no, int a, int b) {
    if (a == b) {
        M[no] = tree(1, 0, 0);
        lazy[no] = 0;
        return;
    }
    int m = (a + b) / 2;
    build(no * 2, a, m);
    build(no * 2 + 1, m + 1, b);
    M[no] = M[no * 2] + M[no * 2 + 1];
    lazy[no] = 0;
}

void propagate(int no, int a, int b) {
    // cout << "propagate no " << no << "\n";
    if (lazy[no] > 0) {
        if (a != b) {
            lazy[no * 2] = (lazy[no * 2] + lazy[no]) % 3;
            lazy[no * 2 + 1] = (lazy[no * 2 + 1] + lazy[no]) % 3;
        }
        M[no].shift();
        if (lazy[no] == 2)
            M[no].shift();

        lazy[no] = 0;
    }
}
void show(int no, int a, int b) {
    if (1)
        return;
    cout << "no = " << no << ", a = " << a << ", b = " << b << "\n";
}

void update(int no, int a, int b, int i, int j) {
    // show(no,a,b);

    if (lazy[no])
        propagate(no, a, b);
    if (a > b || a > j || b < i)
        return;
    if (a >= i && b <= j) {
        M[no].shift();
        if (a != b) {
            lazy[no * 2] = (lazy[no * 2] + 1) % 3;
            lazy[no * 2 + 1] = (lazy[no * 2 + 1] + 1) % 3;
        }
        return;
    }
    int m = (a + b) / 2;
    update(no * 2, a, m, i, j);
    update(no * 2 + 1, m + 1, b, i, j);

    M[no] = M[no * 2] + M[no * 2 + 1];
}

tree query(int no, int a, int b, int i, int j) {
    // show(no,a,b);

    if (a > b || a > j || b < i)
        return tree(); // completamente fora
    if (lazy[no])
        propagate(no, a, b);
    if (a >= i && b <= j)
        return M[no];

    int m = (a + b) / 2;
    return query(no * 2, a, m, i, j) + query(no * 2 + 1, m + 1, b, i, j);
}

int main() {
    int N, Q, i, j;
    tree ans;
    char op;

    while (scanf("%d %d", &N, &Q) == 2) {

        build(1, 1, N);
        rep(k, 0, Q) {
            scanf(" %c %d %d", &op, &i, &j);
            if (op == 'M')
                update(1, 1, N, i, j);
            else {
                ans = query(1, 1, N, i, j);
                printf("%lld %lld %lld\n", ans.h, ans.e, ans.r);
            }
        }
        printf("\n");
    }
    return 0;
}