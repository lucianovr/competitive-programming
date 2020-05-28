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

#define MAXN 212345
vector<int> tree[4 * MAXN];
int N, K;
int A[MAXN];
long long mod = 1000000000 + 7;

void build(int no, int i, int j) {
    tree[no].clear();

    if (i == j) {
        tree[no].push_back(A[i]);
    } else {
        int m = (i + j) / 2;
        build(no * 2, i, m);
        build(no * 2 + 1, m + 1, j);
        tree[no].clear();
        for (int k = 0; k < tree[no * 2].size(); k++) {
            int x = tree[no * 2][k];
            tree[no].pb(x);
        }

        for (int k = 0; k < tree[no * 2 + 1].size(); k++) {
            int x = tree[no * 2 + 1][k];
            tree[no].pb(x);
        }

        sort(tree[no].begin(), tree[no].end());
        reverse(tree[no].begin(), tree[no].end());
        while ((int)tree[no].size() > K)
            tree[no].pop_back();
    }
}

vector<int> query(int no, int i, int j, int a, int b) {
    vector<int> v1, v2;
    if (i > b || j < a)
        return v1;
    if (i >= a && j <= b)
        return tree[no];

    int m = (i + j) / 2;

    v1 = query(no * 2, i, m, a, b);
    v2 = query(no * 2 + 1, m + 1, j, a, b);
    rep(k, 0, v2.size()) v1.pb(v2[k]);

    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    while (v1.size() > K)
        v1.pop_back();

    return v1;
}

int main() {
    int R;
    scanf("%d %d %d", &N, &K, &R);
    rep(i, 0, N) { scanf("%d", &A[i]); }
    build(1, 0, N - 1);

    vector<int> r;
    long long resp;
    while (R--) {
        int i, j;
        scanf("%d %d", &i, &j);
        i--, j--;
        r = query(1, 0, N - 1, i, j);
        resp = r[0];
        if (resp)
            resp %= mod;
        rep(k, 1, min(K, (int)(r.size()))) {
            if (r[k] == 0)
                break;
            resp = ((resp % mod) * (r[k] % mod)) % mod;
        }
        printf("%lld\n", resp);
    }
    return 0;
}
