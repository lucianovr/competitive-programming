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
typedef long long ll;

int dist[1000001], sum[1000001][13];

void crivo(ll upper) {
    bitset<1000001> bs;
    bs.set();
    vector<ll> p;

    for (ll i = 2; i < upper; i++) {
        rep(j, 0, 13) sum[i][j] = sum[i - 1][j];

        if (bs[i]) {
            p.pb(i);
            for (ll j = i * i; j < upper; j += i)
                bs[j] = 0;
            dist[i] = 1;
            sum[i][1]++;
        } else {
            ll n = i;
            int k = 0;
            int soma = 0;
            while (p[k] * p[k] <= n) {
                if (n % p[k] == 0) {
                    while (n % p[k] == 0)
                        n /= p[k];
                    soma += p[k];
                }
                k++;
            }
            if (n > 1)
                soma += n;
            dist[i] = dist[soma] + 1;
            sum[i][dist[i]]++;
        }
    }
}

int main() {
    crivo(1000001);

    int t, a, b, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &k);
        if (k > 12)
            printf("0\n");
        else {
            printf("%d\n", sum[b][k] - sum[a - 1][k]);
        }
    }
    return 0;
}
