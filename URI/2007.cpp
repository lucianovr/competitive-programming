#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

struct point {
    int x, y;
    ll valor;
    point(int x = 0, int y = 0, ll valor = 0) : x(x), y(y), valor(valor) {}
};

int order;
bool comp(point a, point b) { // just for sort the points
    if (order == 0) {         // por menor x
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    } else {
        if (a.y != b.y)
            return a.y < b.y;
        return a.x < b.x;
    }
}

void show(point p) { cout << p.x << " " << p.y << "\n"; }

#define PLANTA 0
#define PAREDE 1
struct event {
    int x;      // just for sorting
    int yi, yf; // limits
    int tipo;   // is a segment or a plant?
    ll valor;
    event(int x = 0, int yi = 0, int yf = 0, int tipo = 0, ll valor = 0)
        : x(x), yi(yi), yf(yf), tipo(tipo), valor(valor) {}
};

vector<event> E;

bool comp_events(event a, event b) { return a.x < b.x; }

int BIT[200000 + 10];
int MAX_Y;
void update(int y, int v) {
    while (y <= MAX_Y) {
        BIT[y] += v;
        y += y & -y;
    }
}

int query(int y) {
    int s = 0;
    while (y > 0) {
        s += BIT[y];
        y -= y & -y;
    }
    return s;
}

ll LineSweep() {
    ll soma = 0;

    for (int i = 0; i < E.size(); i++) {
        event e = E[i];
        if (e.tipo == PAREDE) {
            update(e.yi, 1);
            update(e.yf, -1);
        } else {
            int ret = query(e.yi);
            if (ret % 2 == 0) {
                soma += e.valor;
            }
        }
    }
    return soma;
}

int main() {

    map<int, int> mpx, mpy;

    vector<point> P, V, T;
    int p, v;
    while (scanf("%d %d", &p, &v) == 2) {

        P.resize(p);
        V.resize(v);
        T.clear();
        mpx.clear();
        mpy.clear();
        E.clear();

        rep(i, 0, p) {
            scanf("%d %d", &P[i].x, &P[i].y);
            P[i].valor = i + 1;
            T.pb(P[i]);
        }
        rep(i, 0, v) {
            scanf("%d %d", &V[i].x, &V[i].y);
            T.pb(V[i]);
        }

        order = 0; // por x
        int X = 1;
        sort(ALL(T), comp);
        for (int i = 0; i < T.size(); i++)
            if (mpx.count(T[i].x) == 0)
                mpx[T[i].x] = X++;

        order = 1;
        int Y = 1;
        sort(ALL(T), comp);
        for (int i = 0; i < T.size(); i++)
            if (mpy.count(T[i].y) == 0)
                mpy[T[i].y] = Y++;
        MAX_Y = Y + 2;
        rep(i, 0, MAX_Y) BIT[i] = 0;

        //  Criando os eventos
        for (int i = 0; i < p; i++) {
            P[i] = point(mpx[P[i].x], mpy[P[i].y], P[i].valor);
            E.pb(event(P[i].x, P[i].y, P[i].y, PLANTA, P[i].valor));
        }

        for (int i = 0; i < v; i++) {
            V[i] = point(mpx[V[i].x], mpy[V[i].y]);
        }

        for (int i = 0; i < v - 1; i++)
            if (V[i].x == V[i + 1].x)
                E.pb(event(V[i].x, min(V[i].y, V[i + 1].y), max(V[i].y, V[i + 1].y), PAREDE, 0));
        if (V[0].x == V[v - 1].x)
            E.pb(event(V[0].x, min(V[0].y, V[v - 1].y), max(V[0].y, V[v - 1].y), PAREDE, 0));

        sort(ALL(E), comp_events);

        ll soma = LineSweep();

        printf("%lld\n", soma);
    }

    return 0;
}
