#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

#define printMatriz(M, r, c)                                                                                           \
    rep(i, 0, r) {                                                                                                     \
        printVetor(M[i], c);                                                                                           \
        cout << endl;                                                                                                  \
    }
#define printVetor(V, n) rep(j, 0, n) cout << V[j] << " ";

const double EPS = 1e-10, tol = 1e-3, NULO = -1.0;
inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

struct point {
    double x, y;
    point(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }

    double operator%(point q) { return x * q.y - y * q.x; }
    double operator*(point q) { return x * q.x + y * q.y; }

    friend ostream &operator<<(ostream &o, point p) { return o << "(" << p.x << ", " << p.y << ")"; }
};

struct segment {
    point a, b;
    segment(point _a = point(0, 0), point _b = point(0, 0)) {
        a = _a;
        b = _b;
    }
};

int ccw(point p, point q, point r) { // p->q->r eh giro a esquerda, direita, ou sem giro (linha reta)
    // apenas verificar o sinal do prod vetorial entre os vetores PQ e QR
    point U = q - p;
    point V = r - q;
    double d1, d2;

    d1 = U.x * V.y;
    d2 = U.y * V.x;
    return cmp(d1 - d2);
}

double abs(point p) { return hypot(p.x, p.y); }

int M, T, C, V, ini, fim;

point pts[300];
segment seg[100];
int cabine[300];

double dist[300][300];

bool entre(point i, point j, point k) { // true se I esta entre os pontos J e K
    if (min(j.x, k.x) <= i.x && i.x <= max(j.x, k.x) && min(j.y, k.y) <= i.y && i.y <= max(j.y, k.y))
        return true;
    return false;
}

bool intersectSegment(point A, point B, point C, point D, int i, int j) {
    int d1 = ccw(A, C, D), d2 = ccw(B, C, D), d3 = ccw(C, A, B), d4 = ccw(D, A, B);

    // cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
    if (d1 * d2 == -1 && d3 * d4 == -1)
        return true; // intercepta

    if (d3 == 0) { // extremo C da parede esta colinear com os pts A e B
        if (entre(C, A, B)) {
            if (cabine[i] && cabine[j])
                return true; // intercepta
        }
    }

    if (d4 == 0) { // extremo D da parede esta colinear com os pts A e B
        if (entre(D, A, B)) {
            if (cabine[i] && cabine[j])
                return true; // intercepta
        }
    }
    return false; // nao intercepta
}

bool teste(int i, int j, int s) { return intersectSegment(pts[i], pts[j], seg[s].a, seg[s].b, i, j); }

void montaGrafo() {
    bool ret;
    rep(i, 0, V) {
        rep(j, i + 1, V) {
            dist[i][j] = dist[j][i] = -1.0;
            ret = false;
            rep(s, 0, M) {
                ret = teste(i, j, s);
                if (ret) { // interecepta
                    // cout << "parede: " << s <<" intercepta pts " << pts[i] << "  " << pts[j] << "\n";
                    break;
                }
            }

            if (ret == false) {
                // cout << "NAO intercepta pts " <<  pts[i] << "  " << pts[j] << "\n\n";
                dist[i][j] = dist[j][i] = abs(pts[i] - pts[j]);
            }
        }
    }
}

double dijkstra() {
    double D[V + 3][T + 3], cost;
    int vis[V + 3][T + 3], v, u, t, i;

    for (i = 0; i < V; i++)
        for (t = 0; t <= T + 1; t++) {
            D[i][t] = -1.0;
            vis[i][t] = 0;
        }
    priority_queue<pair<double, ii>> fila;

    fila.push(make_pair(D[ini][0] = 0.0, ii(ini, 0)));

    while (!fila.empty()) {
        ii top = fila.top().second;
        fila.pop();

        u = top.first;
        t = top.second;

        if (t > T || vis[u][t])
            continue;

        vis[u][t] = 1;

        for (v = 0; v < V; ++v) {
            if (v != u && dist[u][v] >= 0) // caso haja caminho de u -> v
            {
                if (!vis[v][t]) {
                    if (D[v][t] == NULO || D[v][t] > (D[u][t] + dist[u][v])) {
                        D[v][t] = (D[u][t] + dist[u][v]);
                        fila.push(make_pair(-D[v][t], ii(v, t)));
                    }
                }
                if (cabine[u] && cabine[v]) {
                    if (!vis[v][t + 1]) {
                        if (D[v][t + 1] == NULO || D[v][t + 1] > (D[u][t] + 0.0)) {
                            D[v][t + 1] = (D[u][t] + 0.0);
                            fila.push(make_pair(-D[v][t + 1], ii(v, t + 1)));
                        }
                    }
                }
            }
        }
    }
    double ans = -1.0;

    for (t = 0; t <= T; t++) {
        if (D[fim][t] != -1.0) {
            if (ans == -1.0)
                ans = D[fim][t];
            else
                ans = min(ans, D[fim][t]);
        }
    }
    return ans;
}

int main() {

    int x1, y1, x2, y2;

    while (scanf("%d%d%d", &T, &M, &C) && T + M + C) {
        memset(cabine, 0, sizeof(cabine));
        int k = 0;
        for (int m = 0; m < M; m++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            seg[m] = segment(point(x1, y1), point(x2, y2));
            pts[k++] = point(x1, y1);
            pts[k++] = point(x2, y2);
        }
        for (int c = 0; c < C; c++) {
            scanf("%d%d", &x1, &y1);
            pts[k] = point(x1, y1);
            cabine[k++] = 1;
        }

        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        pts[k] = point(x1, y1);
        ini = k;
        k++;
        pts[k] = point(x2, y2);
        fim = k;
        k++;
        V = k; // number of vertices

        montaGrafo();
        double ret = dijkstra() + 0.5;

        printf("%d\n", int(ret));
    }
    return 0;
}
