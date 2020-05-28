#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

const int NN = 100000 + 5;
int tree[4 * NN], lazy[4 * NN];
bool islazy[4 * NN];

int arr[NN];
int N;

#define upd(no) (tree[no] = tree[no * 2] ^ tree[no * 2 + 1])

void build(int no, int a, int b) {
    lazy[no] = 0;
    islazy[no] = false;
    if (a == b) {
        tree[no] = arr[a];
    } else {
        int m = (a + b) / 2;
        build(no * 2, a, m);
        build(no * 2 + 1, m + 1, b);
        upd(no);
    }
}
void propagate(int no, int a, int b) {
    if (islazy[no] == false)
        return;

    if ((b - a + 1) % 2 == 0)
        tree[no] = 0;
    else
        tree[no] = lazy[no];

    if (a != b) {
        lazy[no * 2 + 1] = lazy[no];
        lazy[no * 2] = lazy[no];

        islazy[no * 2 + 1] = true;
        islazy[no * 2] = true;
    }
    lazy[no] = 0;
    islazy[no] = false;
}
void update(int no, int a, int b, int i, int j, int v) {
    propagate(no, a, b);
    if (a > j || b < i)
        return;
    else if (a >= i && b <= j) {
        lazy[no] = v;
        islazy[no] = true;
        propagate(no, a, b);
    } else {
        int m = (a + b) / 2;
        update(no * 2, a, m, i, j, v);
        update(no * 2 + 1, m + 1, b, i, j, v);
        upd(no);
    }
}

int query(int no, int a, int b, int i, int j) {
    propagate(no, a, b);
    if (a > j || b < i)
        return 0;
    else if (a >= i && b <= j)
        return tree[no];
    else {
        int m = (a + b) / 2;
        return query(no * 2, a, m, i, j) ^ query(no * 2 + 1, m + 1, b, i, j);
    }
}

int main() {
    int M, x, y, v;
    while (scanf("%d", &N) != EOF) {
        scanf("%d", &M);
        for (int i = 1; i <= N; i++)
            scanf("%d", &arr[i]);

        build(1, 1, N);

        while (M--) {
            scanf("%d %d %d", &x, &y, &v);
            update(1, 1, N, x, y, v);
            int ret = query(1, 1, N, 1, N);
            if (ret == 0)
                printf("Impossivel\n");
            else
                printf("Possivel\n");
        }
    }
    return 0;
}