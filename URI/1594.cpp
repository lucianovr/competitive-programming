#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

ll A[1000111];

ll SlidingWindow(int n, int K) {
    deque<pair<ll, int>> window;
    ll soma = 0;
    for (int i = 0; i < n; i++) {
        while (!window.empty() && window.back().fst >= A[i])
            window.pop_back();
        window.push_back(mp(A[i], i));
        while (window.front().snd <= i - K)
            window.pop_front();

        if (i + 1 >= K) {
            soma += window.front().first;
        }
    }
    return -soma;
}
void build(int N, ll S) {
    A[0] = S;
    for (int i = 1; i < N; ++i)
        A[i] = (1LL * A[i - 1] * 1103515245 + 12345) % (2147483648LL);

    for (int i = 0; i < N; i++)
        A[i] *= -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1594.txt", "r", stdin);
    freopen("1594out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    rep(tt, 0, t) {
        int N, K;
        ll S;
        scanf("%d %d %lld", &N, &K, &S);
        build(N, S);
        printf("%lld\n", SlidingWindow(N, K));
    }

    return 0;
}
