#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;
typedef pair<double, double> ponto;
typedef pair<ponto, ponto> segmento;

#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())
#define x first
#define y second
double const EPS = 1e-10;
int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }
int cmp_eq(double x, double y) { return cmp(x, y) == 0; }
int cmp_lt(double x, double y) { return cmp(x, y) < 0; }

vector<segmento> S;

double mod(ponto a, ponto b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

double escalar(ponto p, ponto c, ponto d) {
    double ax, ay, bx, by;
    ax = c.x - p.x;
    ay = c.y - p.y;
    bx = d.x - p.x;
    by = d.y - p.y;
    return (ax * bx + ay * by);
}
double funcao(ponto p, segmento s) {
    ponto a = s.first;
    ponto b = s.second;
    double ux = p.x - a.x, uy = p.y - a.y;
    double vx = b.x - a.x, vy = b.y - a.y;
    double prodVet = ux * vy - uy * vx;
    double modulo = sqrt(vx * vx + vy * vy);
    double h = prodVet / modulo;
    if (cmp_lt(h, 0))
        h = -h;
    return h;
}

int main() {

    int N;
    double L, H;
    while (cin >> N) {
        cin >> L >> H;
        S.resize(N);
        double yi, xf, yf;
        double dist = 10000000.0;
        double d;
        rep(i, N) {
            cin >> yi >> xf >> yf;
            if (i % 2 == 0) {
                S[i] = segmento(ponto(0, yi), ponto(xf, yf));
                d = L - xf;
            } else {
                S[i] = segmento(ponto(L, yi), ponto(xf, yf));
                d = xf;
            }

            if (cmp_lt(d, dist))
                dist = d;
        }
        double NUM, DEN, cos_fi;
        for (int i = 0; i < N - 1; i++) {
            NUM = escalar(S[i + 1].second, S[i + 1].first, S[i].second);
            DEN = mod(S[i + 1].second, S[i + 1].first) * mod(S[i].second, S[i + 1].second);
            cos_fi = NUM / DEN;

            if (cmp_lt(0.0, cos_fi))
                d = funcao(S[i].second, S[i + 1]);
            else
                d = mod(S[i].second, S[i + 1].second);

            if (cmp_lt(d, dist))
                dist = d;
        }
        cout << fixed << setprecision(2) << dist << endl;
    }

    return 0;
}
