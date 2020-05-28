#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define MAX_CIRCLES 35

const double EPS = 1e-9;
typedef double PTYPE;

inline int cmp(PTYPE x, PTYPE y = 0, PTYPE tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

struct point {
    PTYPE x, y;
    point(PTYPE x = 0, PTYPE y = 0) : x(x), y(y) {}
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double t) { return point(x * t, y * t); }
    point operator/(double t) { return point(x / t, y / t); }
    point operator/(point q) { // divisao de num complexos
        return point(x * q.x + y * q.y, y * q.x - x * q.y) / q.norma2();
    }
    PTYPE norma2() { return (*this) * (*this); } // |u|^2
    PTYPE operator*(point q) { return x * q.x + y * q.y; }
    PTYPE operator%(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }
    bool operator==(point q) const { return cmp(q) == 0; };
    bool operator!=(point q) const { return cmp(q) != 0; };
    bool operator<(point q) const { return cmp(q) < 0; };
};
ostream &operator<<(ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; }
#define vec(a, b) (b - a)
typedef vector<point> polygon;

// rotate a point CCW or CW around the origin
point RotateCCW90(point p) { return point(-p.y, p.x); }
point RotateCW90(point p) { return point(p.y, -p.x); }
point RotateCCW(point p, double t) { return point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)); }

// modulo de um vetor
double abs(point u) { return sqrt(1.0 * (u * u)); }

//	Determina se o giro formado por P->Q e Q->R eh CW ou CCW
// 1: esq, 0: colinear, -1:direita
int ccw(point p, point q, point r) { return cmp(vec(p, q) % (vec(q, r))); }

//	Encontra o vetor projecao de A na direcao de B
point project(point a, point b) { return b * ((a * b) / (b * b)); }

// Projeta o ponto P na reta sobre os pontos A e B
point projectPointLine(point p, point a, point b) { return p + project(p - a, b - a); }

//	Retorna o angulo entre os vetores qp e qr
double arg(point p, point q, point r) {
    point u = vec(q, p), v = vec(q, r);
    return atan2(u % v, u * v);
}

//	Determina se q esta entre o segmento fechado [p, r], inclusive
bool between(point p, point q, point r) { return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0; }

// Distancia de ponto P ao segmento [A,B]
double distancePointSeg(point p, point a, point b) {
    if ((b - a) * (p - a) <= 0)
        return abs(a - p);
    if ((a - b) * (p - b) <= 0)
        return abs(b - p);
    return fabs((b - a) % (p - a)) / abs(a - b);
}

// Determina se os segmentos [A, B] e [C, D] se tocam
bool seg_intersect(point a, point b, point c, point d) {
    int d1, d2, d3, d4;
    d1 = ccw(c, a, d);
    d2 = ccw(c, b, d);
    d3 = ccw(a, c, b);
    d4 = ccw(a, d, b);
    if (d1 * d2 == -1 && d3 * d4 == -1)
        return true;
    if (d1 == 0 && between(c, a, d))
        return true;
    if (d2 == 0 && between(c, b, d))
        return true;
    if (d3 == 0 && between(a, c, b))
        return true;
    if (d4 == 0 && between(a, d, b))
        return true;
    return false;
}

// Encontra a interseccao das retas (p-q) e (r-s)
point line_intersect(point p, point q, point r, point s) {
    point a = q - p, b = s - r, c = point(p % q, r % s);
    return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}

//******************************************************************************************************

typedef pair<point, PTYPE> circle;

bool circle_circle_intersect(circle a, circle b) {
    double d = abs(a.first - b.first);
    double ra = a.second;
    double rb = b.second;

    double rS = ra + rb;
    double rD = ra - rb;

    if (d * d > rS * rS)
        return false; // circles are disjoints
    if (d * d < rD * rD)
        return false; // once circle is inside another

    return true; // they have one or two point in commom
}

vector<circle> radars;
vector<point> pessoas;

polygon border;
vector<vector<point>> polygons; // poligons formados pelos circulos

vector<int> adj[MAX_CIRCLES];
int cor[MAX_CIRCLES];
int pai[MAX_CIRCLES];

void init() {
    radars.clear();
    pessoas.clear();
    border.clear();
    polygons.clear();
    for (int i = 0; i < MAX_CIRCLES; i++)
        adj[i].clear();
}

void constroiGrafo() {
    rep(i, 0, radars.size()) rep(j, i + 1, radars.size()) if (circle_circle_intersect(radars[i], radars[j])) adj[i]
        .push_back(j),
        adj[j].push_back(i);
}

#define BRANCO 0
#define CINZA 1
#define PRETO 2

void dfs(int u) {
    cor[u] = CINZA;
    rep(i, 0, adj[u].size()) {
        int v = adj[u][i];
        if (cor[v] == BRANCO) {
            pai[v] = u;
            dfs(v);
        } else if (cor[v] == CINZA && v != pai[u]) {
            // ciclo encontrado
            vector<int> ciclo;
            ciclo.push_back(v);
            int aux = u;
            while (aux != v) {
                ciclo.push_back(aux);
                aux = pai[aux];
            }

            polygon paux;
            rep(i, 0, ciclo.size()) paux.push_back(radars[ciclo[i]].first);
            polygons.push_back(paux);
        }
    }
    cor[u] = PRETO;
}

void DFS() {
    memset(cor, BRANCO, sizeof cor);
    memset(pai, -1, sizeof pai);

    for (int u = 0; u < radars.size(); u++)
        if (cor[u] == BRANCO)
            dfs(u);
}

bool dentro_circulo(point p) {
    rep(i, 0, radars.size()) {
        if (cmp(abs(p - radars[i].first), radars[i].second) <= 0)
            return true;
    }
    return false;
}

double dist2border(point p) {
    int N = border.size();
    double ans = -1;
    rep(i, 0, N) {
        double dd = distancePointSeg(p, border[i], border[(i + 1) % N]);
        if (ans < 0 || dd < ans)
            ans = dd;
    }
    return ans;
}

//	Determina se P pertence a T, funciona para convexo ou concavo
// -1 borda, 0 fora, 1 dentro
int in_poly(point p, polygon &T) {
    double a = 0;
    int N = T.size();
    rep(i, 0, N) {
        if (between(T[i], p, T[(i + 1) % N]))
            return -1;
        a += arg(T[i], p, T[(i + 1) % N]);
    }
    return cmp(a) != 0;
}
bool dentro_poligono(point p) {
    rep(i, 0, polygons.size()) {
        if (in_poly(p, polygons[i]))
            return true;
    }
    return false;
}

int solve() {
    double minDist = -1, idx = -1;
    for (int i = 0; i < pessoas.size(); i++) {
        if (dentro_circulo(pessoas[i]) || dentro_poligono(pessoas[i]))
            continue;
        double dd = dist2border(pessoas[i]);
        if (idx == -1 || cmp(dd, minDist) == 1) {
            idx = i;
            minDist = dd;
        }
    }
    return idx;
}

int main() {

    int B, N, M;
    point p;
    PTYPE radius;
    while (cin >> B) {
        init();

        rep(i, 0, B) {
            cin >> p.x >> p.y;
            border.push_back(p);
        }

        cin >> N;
        rep(i, 0, N) {
            cin >> p.x >> p.y;
            pessoas.push_back(p);
        }

        cin >> M;
        rep(i, 0, M) {
            cin >> p.x >> p.y >> radius;
            radars.push_back(make_pair(p, radius));
        }

        if (B == 0 && N == 0 && M == 0)
            break;
        constroiGrafo();
        DFS();

        int r = solve();
        if (r < 0)
            printf("Mission impossible\n");
        else {
            printf("Contact informer %d\n", r + 1);
        }
    }
    return 0;
}
