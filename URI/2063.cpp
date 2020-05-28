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

    int n;
    vector<int> b;
    while (cin >> n) {
        b.resize(n);
        rep(i, 0, n) {
            cin >> b[i];
            --b[i];
        }
        vector<int> vis(n, 0);

        int mmc = 1;
        rep(i, 0, n) {
            if (!vis[i]) {
                vis[i] = 1;
                int cont = 1;

                int a = b[i];
                while (!vis[a]) {
                    vis[a] = 1;
                    cont++;

                    a = b[a];
                }
                mmc = (cont / __gcd(cont, mmc)) * mmc;
            }
        }
        cout << mmc << "\n";
    }
    return 0;
}
