#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define D(x) cout << #x << " = " << x << endl;
#define D2(x, y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

long long r1, r2;

struct ponto {
    ponto(ll x = 0, ll y = 0) : x(x), y(y) {}

    ll x, y;
};

ll norma2(ponto v) { return v.x * v.x + v.y * v.y; }

ponto c;

int status(ponto p) {
    ponto v;
    v.x = p.x - c.x;
    v.y = p.y - c.y;

    ll dist = norma2(v);

    if (dist < r1)
        return 1;
    if (dist == r1)
        return 0;

    if (dist <= r2)
        return 0;

    if (dist > r2)
        return -1;
}

int main() {
    int n;
    ponto p;

    while (cin >> n && n) {
        cin >> c.x >> c.y >> r1 >> r2;
        r1 = r1 * r1;
        r2 = r2 * r2;

        int dc, dp, bc, bp;
        dc = dp = bc = bp = 0;

        rep(i, 0, 2 * n) {
            cin >> p.x >> p.y;

            int r = status(p); // -1 fora, 0 borda, 1 dentro

            if (i % 2 == 0) { // chiquinha
                if (r == 1)
                    dc++;
                else if (r == 0)
                    bc++;
            } else {
                if (r == 1)
                    dp++;
                else if (r == 0)
                    bp++;
            }
        }

        if (dc > dp || dc == dp && bc > bp)
            cout << "C > P\n";
        else if (dp > dc || dc == dp && bp > bc)
            cout << "P > C\n";
        else
            cout << "C = P\n";
    }
    return 0;
}
