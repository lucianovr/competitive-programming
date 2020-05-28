#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

const int NN = 4 * 100010;
ll tree[NN];
ll lazy[NN];
ll arr[100010];
int hasLazy[NN];
int pos;

void propagate(int no, int a, int b) {
    if (hasLazy[no]) {
        tree[no] += (b - a + 1) * lazy[no];
        if (a != b) {
            lazy[2 * no] += lazy[no];
            hasLazy[2 * no] = 1;
            lazy[2 * no + 1] += lazy[no];
            hasLazy[2 * no + 1] = 1;
        }
    }
    hasLazy[no] = 0;
    lazy[no] = 0;
}

void update(int no, int a, int b, int i, int j, int v) {
    propagate(no, a, b);
    if (a > j || b < i)
        return;
    if (a >= i && b <= j) {
        hasLazy[no] = 1;
        lazy[no] += v;
        propagate(no, a, b);
        return;
    }
    int m = (a + b) / 2;
    update(no * 2, a, m, i, j, v);
    update(no * 2 + 1, m + 1, b, i, j, v);
    tree[no] = tree[no * 2] + tree[no * 2 + 1];
}

ll query(int no, int a, int b, int i, int j) {
    propagate(no, a, b);
    if (a > j || b < i)
        return 0;
    if (a >= i && b <= j)
        return tree[no];
    int m = (a + b) / 2;
    return query(no * 2, a, m, i, j) + query(no * 2 + 1, m + 1, b, i, j);
}

void build(int no, int a, int b) {
    lazy[no] = hasLazy[no] = 0;

    if (a == b) {
        tree[no] = arr[a];
    } else {
        int m = (a + b) / 2;
        build(no * 2, a, m);
        build(no * 2 + 1, m + 1, b);
        tree[no] = tree[no * 2] + tree[no * 2 + 1];
    }
}

int main() {
    int N, K;
    while (scanf("%d %d", &K, &N) == 2) {
        pos = 1;
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &arr[i]);
        }
        sort(arr + 1, arr + N + 1);

        build(1, 1, N);

        char op;
        long long sum = 0;
        for (int i = 0; i < K; i++) {
            scanf(" %c", &op);
            if (pos <= N) {
                if (op == 'C') {
                    update(1, 1, N, pos, N, +1);
                } else {
                    update(1, 1, N, pos, N, -1);

                    //					for (int j = 1; j <= N; j++)
                    //					cout<<query(1,1,N,j,j)<<" " ; cout << endl;

                    while (pos <= N) { // atualmente pos nao vale zero
                        if (query(1, 1, N, pos, pos) == 0)
                            pos++;
                        else
                            break;
                    }
                    //			printf("Estiagem pos = %d\n", pos);
                }
                //	printf("Colheita %lld\n", query(1,1,N,pos,N));
                sum += query(1, 1, N, pos, N);
            }
        }
        printf("%lld\n", sum);
    }

    return 0;
}
