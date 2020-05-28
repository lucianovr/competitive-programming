#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define SORT(c) sort(all(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz(c) ((int)(c.size()))
#define fst first
#define snd second
#define clr(x) memset(x, 0, sizeof x)
#define nulo(x) memset(x, -1, sizeof x)
#define debug(x) cout << #x << " = " << x << "\n";
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << "\n";
#define debugV(v)                                                                                                      \
    {                                                                                                                  \
        cout << #v << "[] = ";                                                                                         \
        rep(i, 0, sz(v)) cout << v[i] << " ";                                                                          \
        cout << "\n";                                                                                                  \
    }

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<string, string> mss;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    int S;
    while (scanf("%d", &S) > 0) {
        int Q[S], N[S];
        rep(i, 0, S) scanf("%d", &Q[i]);
        rep(i, 0, S) scanf("%d", &N[i]);
        sort(Q, Q + S);
        reverse(Q, Q + S);
        sort(N, N + S);
        reverse(N, N + S);

        int i = 0, j = 0, vit = 0;

        for (j = 0; j < S; j++) {
            while (i < S && Q[i] >= N[j])
                i++;
            if (i < S) {
                vit++;
                i++;
            }
        }
        printf("%d\n", vit);
    }

    return 0;
}
