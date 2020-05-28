#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

double MOD(double x) {
    if (x < 0)
        return -x;
    return x;
}

struct ponto {
    double x, y;
};
struct segmento {
    ponto pa, pb;
    int ang;
} s[1010];
double madj[1010][1010];

double dijkstra(int n, int s, int destino) {
    double d[1010];
    int vis[1010];
    for (int i = 0; i < 1010; i++) {
        vis[i] = 0;
        d[i] = 2000000000.00;
    }
    priority_queue<pair<double, int>> Q;
    d[s] = 0;
    Q.push(make_pair(0.00, s));

    while (!Q.empty()) {
        s = Q.top().second;
        Q.pop();
        // if (s == d) break;
        if (vis[s])
            continue;
        vis[s] = 1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (d[i] > max(madj[s][i], d[s])) {
                    d[i] = max(madj[s][i], d[s]);
                    Q.push(make_pair(-d[i], i));
                }
            }
        }
    }
    return d[destino];
}

int turn(ponto pi, ponto pj, ponto pk) {
    double ux, uy, vx, vy;
    ux = pk.x - pi.x;
    uy = pk.y - pi.y;
    vx = pj.x - pi.x;
    vy = pj.y - pi.y;

    double cross = ux * vy - uy * vx;

    if (cross > 0)
        return 1;
    if (cross < 0)
        return -1;
    return 0;
}

bool on_segment(ponto pi, ponto pj, ponto pk) {
    if (min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) && min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y))
        return true;
    return false;
}

bool segments_intersect(ponto p1, ponto p2, ponto p3, ponto p4) {
    int d1, d2, d3, d4;
    d1 = turn(p3, p4, p1);
    d2 = turn(p3, p4, p2);
    d3 = turn(p1, p2, p3);
    d4 = turn(p1, p2, p4);
    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;

    if (d1 == 0 && on_segment(p3, p4, p1))
        return true;
    if (d2 == 0 && on_segment(p3, p4, p2))
        return true;
    if (d3 == 0 && on_segment(p1, p2, p3))
        return true;
    if (d4 == 0 && on_segment(p1, p2, p4))
        return true;

    return false;
}

bool perpend(ponto pi, ponto pj, ponto pk) {
    if ((min(pi.x, pj.x) < pk.x && pk.x < max(pi.x, pj.x)) || (min(pi.y, pj.y) < pk.y && pk.y < max(pi.y, pj.y)))
        return true;
    return false;
}

bool teste(ponto p1, ponto p2, ponto p3, ponto p4) {
    if (perpend(p1, p2, p3))
        return true;
    if (perpend(p1, p2, p4))
        return true;
    if (perpend(p3, p4, p1))
        return true;
    if (perpend(p3, p4, p2))
        return true;
    return false;
}

bool entreX(ponto pi, ponto pj, ponto pk) {
    if (min(pi.x, pj.x) < pk.x && pk.x < max(pi.x, pj.x))
        return true;
    return false;
}

bool entreY(ponto pi, ponto pj, ponto pk) {
    if (min(pi.y, pj.y) < pk.y && pk.y < max(pi.y, pj.y))
        return true;
    return false;
}

double dist_facil(ponto p1, ponto p2, ponto p3, ponto p4, int i, int j) {
    if (entreX(p1, p2, p3) || entreX(p1, p2, p4))
        return min(MOD(p3.y - p1.y), MOD(p4.y - p1.y));

    if (entreX(p3, p4, p1) || entreX(p3, p4, p2))
        return min(MOD(p2.y - p3.y), MOD(p1.y - p3.y));

    if (entreY(p1, p2, p3) || entreY(p1, p2, p4))
        return min(MOD(p3.x - p1.x), MOD(p4.x - p1.x));

    if (entreY(p3, p4, p1) || entreY(p3, p4, p2))
        return min(MOD(p2.x - p3.x), MOD(p1.x - p3.x));
}

double d2_dist(ponto a, ponto b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

double func(ponto p1, ponto p2, ponto p3, ponto p4) {
    double d1, d2, d3, d4;
    d1 = d2_dist(p1, p3);
    d2 = d2_dist(p1, p4);
    d3 = d2_dist(p2, p3);
    d4 = d2_dist(p2, p4);
    return min(min(d1, d2), min(d3, d4));
}
double dist(int i, int j) {
    double zero = 0.00;
    if (segments_intersect(s[i].pa, s[i].pb, s[j].pa, s[j].pb)) // ou se intersectam ou esta contido
        return zero;
    else // nao se intersectam: turn ainda pode ser 0
    {
        if (teste(s[i].pa, s[i].pb, s[j].pa, s[j].pb)) // caso a linha perpendicular passe por eles
            return dist_facil(s[i].pa, s[i].pb, s[j].pa, s[j].pb, i, j);
        else
            return func(s[i].pa, s[i].pb, s[j].pa,
                        s[j].pb); // segmentos independentes, retornar a menor distancia encontrada
    }
}

int main() {
    int n;
    double L;
    cout << fixed << setprecision(2);
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i].pa.x >> s[i].pa.y >> L;
            s[i].pb.x = s[i].pa.x;
            s[i].pb.y = s[i].pa.y;

            if (L >= 0) {
                s[i].pb.x += L;
                s[i].ang = 0;
            } else {
                s[i].ang = 1;
                s[i].pb.y -= L;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (i == j)
                    madj[i][j] = 0.0;
                else
                    madj[i][j] = madj[j][i] = dist(i, j);

        cout << dijkstra(n, 0, 1) << endl;
    }
    return 0;
}