#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long ll;

int cross(ll x1, ll y1, ll x2, ll y2) {
    ll r1 = x1 * y2;
    ll r2 = x2 * y1;
    if (r1 > r2)
        return 1;
    if (r1 < r2)
        return -1;
    return 0;
}

int main() {

    ll x1, x2, y1, y2, dx, dy, x, y;
    int cntO = 0, cntL = 0, casual = 0, h = 0, hO = 0, hL = 0;

    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    dx = x2 - x1;
    dy = y2 - y1;

    int n;
    scanf("%d\n", &n);
    while (n--) {
        scanf("%lld %lld %d", &x, &y, &h);
        int ret = cross(x - x1, y - y1, dx, dy);
        if (ret == -1) // esquerda
            cntO++, hO += h;
        else if (ret == 1) // direita
            cntL++, hL += h;
        else if (ret == 0)
            casual++;
    }

    cout << "Relatorio Vogon #35987-2\n";
    cout << "Distancia entre referencias: ";
    printf("%.2lf", hypot(double(dx), double(dy)));
    cout << " anos-luz\n";
    cout << "Setor Oeste:\n";
    cout << "- " << cntO << " planeta(s)\n";
    cout << "- " << hO << " bilhao(oes) de habitante(s)\n";

    cout << "Setor Leste:\n";
    cout << "- " << cntL << " planeta(s)\n";
    cout << "- " << hL << " bilhao(oes) de habitante(s)\n";

    cout << "Casualidades: " << casual << " planeta(s)\n";

    return 0;
}
