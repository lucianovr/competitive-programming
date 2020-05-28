// Guerra nas estrelas
// Luciano

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const double eps = 1e-9;

struct point {
    double x, y, z;
    void read() { cin >> x >> y >> z; }
    point(){};
    point(double X, double Y, double Z) : x(X), y(Y), z(Z) {}
    point(point p, point q) {
        x = q.x - p.x;
        y = q.y - p.y;
        z = q.z - p.z;
    }

    point operator+(point q) { return point(x + q.x, y + q.y, z + q.z); }
    point operator-(point q) { return point(x - q.x, y - q.y, z - q.z); }
    point operator*(double t) { return point(x * t, y * t, z * t); }
    point operator/(double t) { return point(x / t, y / t, z / t); }
};
typedef point vetor;

struct segmento {
    point a, b;
    segmento(){};
    segmento(point A, point B) : a(A), b(B){};
};

// produto escalar
double dot(const vetor U, const vetor V) { return U.x * V.x + U.y * V.y + U.z * V.z; }

// produto vetorial
point cross(const vetor U, const vetor V) {
    return point(U.y * V.z - U.z * V.y, U.z * V.x - U.x * V.z, U.x * V.y - U.y * V.x);
}

// tamanho do vetor
double abs(vetor p) { return sqrt(dot(p, p)); };

// vetor proje?ao do vetor u sobre o vetor v
vetor projecao(vetor u, vetor v) { return v * (dot(u, v) / dot(v, v)); }

bool between(point p, point a, point b) { return dot(vetor(a, p), vetor(b, p)) < eps; }

// Struct para tri?ngulos
struct triangulo {
    point a, b, c;
    triangulo(point A, point B, point C) : a(A), b(B), c(C){};
};

// Dist?ncia de ponto a segmento
double linedist(point p, point a, point b) {
    vetor PP = a + projecao(vetor(a, p), vetor(a, b));
    if (between(PP, a, b)) {
        return abs(vetor(p, PP));
    } else {
        return min(abs(vetor(a, p)), abs(vetor(b, p)));
    }
}

// Dist?ncia de segmento a segmento

double seg2seg(segmento r, segmento s) {
    vetor u(r.a, r.b), v(s.a, s.b), w(s.a, r.a);
    double a = dot(u, u), b = dot(u, v), c = dot(v, v), d = dot(u, w), e = dot(v, w);
    double D = a * c - b * b;
    double sc, sN, sD = D;
    double tc, tN, tD = D;
    if (D < eps) {
        sN = 0;
        sD = 1;
        tN = e;
        tD = c;
    } else {
        sN = (b * e - c * d);
        tN = (a * e - b * d);
        if (sN < 0) {
            sN = 0;
            tN = e;
            tD = c;
        } else if (sN > sD) {
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }
    if (tN < 0) {
        tN = 0;
        if (-d < 0) {
            sN = 0;
        } else if (-d > a) {
            sN = sD;
        } else {
            sN = -d;
            sD = a;
        }
    } else if (tN > tD) {
        tN = tD;
        if ((-d + b) < 0) {
            sN = 0;
        } else if (-d + b > a) {
            sN = sD;
        } else {
            sN = -d + b;
            sD = a;
        }
    }
    sc = fabs(sN) < eps ? 0 : sN / sD;
    tc = fabs(tN) < eps ? 0 : tN / tD;
    vetor dP = w + (u * sc) - (v * tc);
    return abs(dP);
}

//  Dist?ncia de ponto a semi-plano
double planedist(point p, triangulo T) {
    vetor X(T.a, T.b), Y(T.a, T.c), AP(T.a, p);

    vetor PP = p - projecao(AP, cross(X, Y));

    vetor D1 = cross(vetor(T.a, T.b), vetor(T.a, PP));
    vetor D2 = cross(vetor(T.b, T.c), vetor(T.b, PP));
    vetor D3 = cross(vetor(T.c, T.a), vetor(T.c, PP));

    if (dot(D1, D2) > -eps && dot(D2, D3) > -eps && dot(D3, D1) > -eps) {
        return abs(vetor(PP, p));
    } else {
        return min(min(linedist(p, T.a, T.b), linedist(p, T.b, T.c)), linedist(p, T.a, T.c));
    }
}

int main() {
    int T;
    point A[4], B[4];

    cin >> T;
    while (T--) {
        rep(i, 0, 4) A[i].read();
        rep(i, 0, 4) B[i].read();
        double ans = 0x3f3f3f3f;
        rep(i, 0, 4) {
            ans = min(ans, planedist(B[i], triangulo(A[0], A[1], A[2])));
            ans = min(ans, planedist(B[i], triangulo(A[0], A[1], A[3])));
            ans = min(ans, planedist(B[i], triangulo(A[1], A[2], A[3])));
            ans = min(ans, planedist(B[i], triangulo(A[0], A[2], A[3])));
        }
        rep(i, 0, 4) {
            ans = min(ans, planedist(A[i], triangulo(B[0], B[1], B[2])));
            ans = min(ans, planedist(A[i], triangulo(B[0], B[1], B[3])));
            ans = min(ans, planedist(A[i], triangulo(B[1], B[2], B[3])));
            ans = min(ans, planedist(A[i], triangulo(B[0], B[2], B[3])));
        }

        rep(i, 0, 4) rep(j, i + 1, 4) rep(k, 0, 4) rep(l, 0, 4) ans =
            min(ans, seg2seg(segmento(A[i], A[j]), segmento(B[k], B[l])));

        printf("%.2lf\n", ans);
    }
    return 0;
}
