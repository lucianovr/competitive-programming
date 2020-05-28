#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool cmp(int a, int b) { return a > b; }

int func(int X, bool flag) {
    vi v;
    rep(i, 0, 4) {
        v.pb(X % 10);
        X /= 10;
    }
    if (flag)
        sort(v.begin(), v.end(), cmp);
    else
        sort(v.begin(), v.end());

    int sum = 0;
    rep(i, 0, 4) {
        sum *= 10;
        sum += v[i];
    }
    return sum;
}

int vis[10000];

int kaprekar(int X) {
    int cnt = 0;
    while (X != 6174) {
        if (vis[X])
            return -1;
        vis[X] = 1;
        int newX = func(X, true) - func(X, false);
        X = newX;
        cnt++;
    }
    return cnt;
}

int main() {
    int t, caso = 1, x;
    scanf("%d", &t);
    while (t--) {
        memset(vis, 0, sizeof vis);
        scanf("%d", &x);
        printf("Caso #%d: %d\n", caso++, kaprekar(x));
    }
    return 0;
}
