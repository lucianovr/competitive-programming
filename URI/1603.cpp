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

struct point {
    long long x, y;
    point(long long _x = 0, long long _y = 0) : x(_x), y(_y){};

    point operator-(point q) { return point(x - q.x, y - q.y); }
    long long operator*(point q) { return x * q.x + y * q.y; }
    long long operator%(point q) { return x * q.y - y * q.x; }
};
long long abs(point v) { return v * v; }
#define vec(a, b) (b - a)

vector<point> TT, PP;
struct canal {
    long long dot, cross, esq, dir;
    canal() {}
    canal(long long d, long long c, long long e, long long di) : dot(d), cross(c), esq(e), dir(di){};
    bool operator==(const canal &c) { return (dot == c.dot && cross == c.cross && esq == c.esq && dir == c.dir); }
    bool operator!=(const canal &c) { return !(*this == c); }
};
vector<canal> T, P; // texto, padrao

// KMP
vector<int> pi;

int KMP() {
    pi.resize(P.size());
    pi[0] = -1;
    for (int i = 1; i < P.size(); i++) {
        pi[i] = pi[i - 1];
        while (pi[i] >= 0 && P[pi[i] + 1] != P[i])
            pi[i] = pi[pi[i]];
        if (P[pi[i] + 1] == P[i])
            ++pi[i];
    }
    int k = -1;
    for (int i = 0; i < T.size(); i++) {
        while (k >= 0 && P[k + 1] != T[i])
            k = pi[k];
        if (P[k + 1] == T[i])
            ++k;
        if (k + 1 == P.size())
            return i - k;
    }
    return -1;
}
//

long long area(vector<point> &T) {
    long long area = 0;
    int n = T.size();
    if (n < 3)
        return 0;
    for (int i = 0; i < T.size(); i++) {
        area += T[i] % T[(i + 1) % n];
    }
    return area;
}

int main() {
    // inverter T?
#ifndef ONLINE_JUDGE
    freopen("canal.txt", "r", stdin);
    freopen("canalSaida.out", "w", stdout);
#endif

    int t, p;
    long long x, y;
    while (cin >> t >> p) {
        if (p > t) {
            cout << -1 << "\n";
            continue;
        }

        TT.clear();
        PP.clear();
        rep(i, 0, t) {
            cin >> x >> y;
            TT.pb(point(x, y));
        }
        // if (area(TT) < 0){
        //			for (int i = 1, j = t-1; i < j; i++, j--)	swap(TT[i], TT[j]);
        //		}
        // rep(i,0,t){	debug2(TT[i].x, TT[i].y);	}
        rep(i, 0, p + 1) TT.pb(TT[i]);

        rep(i, 0, p) {
            cin >> x >> y;
            PP.pb(point(x, y));
        }

        T.clear();
        P.clear();
        t = TT.size();
        point u, v;
        for (int i = 1; i < t - 1; i++) {
            u = vec(TT[i - 1], TT[i]);
            v = vec(TT[i], TT[i + 1]);
            T.push_back(canal(u * v, u % v, abs(u), abs(v)));
        }
        p = PP.size();
        for (int i = 1; i < p - 1; i++) {
            u = vec(PP[i - 1], PP[i]);
            v = vec(PP[i], PP[i + 1]);
            P.push_back(canal(u * v, u % v, abs(u), abs(v)));
        }

        if (p == 2) {
            long long tam = abs(vec(PP[0], PP[1]));
            int achou = 0;
            for (int i = 0; !achou && i < TT.size() - 1; i++)
                if (abs(vec(TT[i], TT[i + 1])) == tam) {
                    achou = 1;
                    cout << i + 1 << "\n";
                    break;
                }
            if (!achou)
                cout << -1 << "\n";
        } else {
            int ret = KMP();
            if (ret == -1)
                cout << ret << "\n";
            else
                cout << ret + 1 << "\n";
        }
    }
    return 0;
}