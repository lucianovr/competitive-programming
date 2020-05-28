#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz(c) ((int)(c.size()))
#define fst first
#define snd second
#define clr(x) memset(x, 0, sizeof x)
#define nulo(x) memset(x, -1, sizeof x)

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<string, string> mss;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

vector<string> v;

int main() {

    int n;
    while (scanf("%d", &n) && n) {
        char s[110];

        v.resize(n);
        rep(i, 0, n) {
            scanf("%s", s);
            v[i] = s;
        }
        sort(v.begin(), v.end());
        bool ok = true; // sequencia boa

        for (int i = 1; ok && i < n; i++) {
            if (v[i - 1].size() <= v[i].size())
                if (v[i - 1] == v[i].substr(0, v[i - 1].size()))
                    ok = false;
        }
        ok ? printf("Conjunto Bom\n") : printf("Conjunto Ruim\n");
    }

    return 0;
}
