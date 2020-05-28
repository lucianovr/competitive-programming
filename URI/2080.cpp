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

string func(int cont) {
    string r;
    while (cont) {
        r += '0' + (cont % 10);
        cont /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    string s, r;
    int t, n;

    cin >> t;
    rep(jj, 0, t) {
        if (jj)
            cout << "\n";

        cin >> s >> n;
        cout << s << "\n";
        while (n--) {
            r.clear();
            int i = 0, j, c;
            while (i < s.size()) {
                j = i;
                while (j < s.size() && s[i] == s[j])
                    j++;
                r += func(j - i);
                r += s[i];
                i = j;
            }
            cout << r << "\n";
            s = r;
        }
    }

    return 0;
}
