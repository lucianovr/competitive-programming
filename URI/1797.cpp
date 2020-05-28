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
typedef long long LL;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

struct point {
    double x, y;
    point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    point operator-(point q) { return point(x - q.x, y - q.y); }
    double operator*(point q) { return x * q.x + y * q.y; }
    double operator%(point q) { return x * q.y - y * q.x; }
};

double seg_distance(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;

    if (cmp(b, a + c) >= 0)
        return sqrt(a);
    if (cmp(a, b + c) >= 0)
        return sqrt(b);
    return fabs(A % B) / sqrt(c);
}

struct rec {
    point p[4];
    rec(){};
    rec(point a, point b, point c, point d) {
        p[0] = a;
        p[1] = b;
        p[2] = c;
        p[3] = d;
    }
};

vector<rec> R;

bool func(int i, double D) {
    int cont = 0;

    rec A, B;
    A = R[i];
    B = R[i + 1];

    if (B.p[0].x >= A.p[0].x && B.p[0].x <= A.p[1].x && B.p[0].y <= A.p[0].y && B.p[0].y >= A.p[2].y)
        cont++;
    if (B.p[1].x >= A.p[0].x && B.p[1].x <= A.p[1].x && B.p[1].y <= A.p[0].y && B.p[1].y >= A.p[2].y)
        cont++;
    if (B.p[2].x >= A.p[0].x && B.p[2].x <= A.p[1].x && B.p[2].y <= A.p[0].y && B.p[2].y >= A.p[2].y)
        cont++;
    if (B.p[3].x >= A.p[0].x && B.p[3].x <= A.p[1].x && B.p[3].y <= A.p[0].y && B.p[3].y >= A.p[2].y)
        cont++;

    if (cont > 0)
        return true;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (seg_distance(A.p[i], A.p[(i + 1) % 4], B.p[j]) <= D)
                return true;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (seg_distance(B.p[i], B.p[(i + 1) % 4], A.p[j]) <= D)
                return true;

    return false;
}

int main() {
    int n;
    double D, x, y, L;
    point a, b, c, d;

    scanf("%d %lf", &n, &D);
    R.resize(n);
    rep(i, 0, n) {
        scanf("%lf %lf %lf", &x, &y, &L);
        a = point(x - L / 2, y + L / 2);
        b = point(x + L / 2, y + L / 2);
        c = point(x - L / 2, y - L / 2);
        d = point(x + L / 2, y - L / 2);
        R[i] = rec(a, b, c, d);
    }
    bool ok = true;
    rep(i, 0, n - 1) {
        if (func(i, D) == false) {
            ok = false;
            break;
        }
    }
    ok ? printf("YEAH\n") : printf("OUCH\n");

    return 0;
}
