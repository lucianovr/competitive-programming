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

struct rsq {
    long long val;
    int op;
};
rsq t[163840 * 4];
long long v[163840];

void create(int no, int L, int R) {
    if (L == R) {
        t[no].val = v[L];
        t[no].op = 0;
        return;
    }
    int M = (L + R) >> 1;

    create(no * 2, L, M);
    create(no * 2 + 1, M + 1, R);
    t[no].op = 1 - t[2 * no].op;

    if (t[no].op == 1) {
        t[no].val = t[2 * no].val + t[2 * no + 1].val;
    } else {
        t[no].val = t[2 * no].val - t[2 * no + 1].val;
    }
}

void update(int no, int L, int R, int i, long long V) {
    if (L > i || R < i)
        return;
    if (L == R && L == i) {
        t[no].val = v[i] = V;
        return;
    }

    int M = (L + R) >> 1;
    update(2 * no, L, M, i, V);
    update(2 * no + 1, M + 1, R, i, V);

    if (t[no].op == 1) {
        t[no].val = t[2 * no].val + t[2 * no + 1].val;
    } else {
        t[no].val = t[2 * no].val - t[2 * no + 1].val;
    }
}

int main() {
    int casos;
    int n, q;
    scanf("%d", &casos);

    for (int k = 0; k < casos; k++) {
        scanf("%d %d", &n, &q);
        int size = 1;
        while (size < n) {
            size <<= 1;
            if (size == n)
                break;
        }

        rep(i, 0, size + 1) v[i] = 0;

        rep(i, 1, n + 1) scanf("%d", &v[i]);

        //     no L, R

        create(1, 1, size);

        printf("%d ", t[1].val);

        if (t[1].val % 2 == 0) {
            if (k % 2 == 0)
                printf("Sanches\n");
            else
                printf("Rusa\n");
        } else {
            if (k % 2 == 0)
                printf("Rusa\n");
            else
                printf("Sanches\n");
        }

        while (q--) {
            int idx;
            long long B;
            cin >> idx >> B;
            update(1, 1, size, idx, B);

            printf("%d ", t[1].val);

            if (t[1].val % 2 == 0) {
                if (k % 2 == 0)
                    printf("Sanches\n");
                else
                    printf("Rusa\n");
            } else {
                if (k % 2 == 0)
                    printf("Rusa\n");
                else
                    printf("Sanches\n");
            }
        }
    }
    return 0;
}
