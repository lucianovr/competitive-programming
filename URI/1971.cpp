#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

typedef pair<int, int> point;

point P[4], E;

int cross(point u, point v) {
    int r = u.fst * v.snd - u.snd * v.fst;
    if (r > 0)
        return 1;
    if (r < 0)
        return -1;
    return 0;
}

int dot(point u, point v) { return u.fst * v.fst + u.snd * v.snd; }

point vetor(point a, point b) { return point(b.fst - a.fst, b.snd - a.snd); }

int inTri(point a, point b, point c, point e, int id) {
    if (cross(vetor(a, e), vetor(e, b)) == 0 && dot(vetor(e, a), vetor(e, b)) <= 0) {
        //		cout << "borda1 " << id << "\n";
        return 1;
    }

    if (cross(vetor(a, e), vetor(e, c)) == 0 && dot(vetor(e, a), vetor(e, c)) <= 0) {
        //		cout << "borda2 " << id << "\n";
        return 1;
    }

    if (cross(vetor(b, e), vetor(e, c)) == 0 && dot(vetor(e, b), vetor(e, c)) <= 0) {
        //		cout << "borda3 " << id << "\n";
        return 1;
    }

    int d1 = cross(vetor(a, b), vetor(a, e));
    int d2 = cross(vetor(b, c), vetor(b, e));
    int d3 = cross(vetor(c, a), vetor(c, e));

    if (d1 == d2 && d1 == d3)
        return 1;

    return 0;
}

int main() {

    rep(i, 0, 4) scanf("%d %d", &P[i].fst, &P[i].snd);
    scanf("%d %d", &E.fst, &E.snd);

    if (cross(vetor(P[0], P[1]), vetor(P[2], P[3])) == 0) {
        //	cout << "colinear\n";
        string s1 = " O>";
        string s2 = "<| ";
        string s3 = "/ >";

        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
        return 0;
    }

    if (inTri(P[0], P[1], P[2], E, 1) || inTri(P[0], P[1], P[3], E, 2) || inTri(P[0], P[2], P[3], E, 3) ||
        inTri(P[1], P[2], P[3], E, 4)) {
        // cout << "dentro\n";
        string s1 = "\\O/";
        string s2 = " | ";
        string s3 = "/ \\";

        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;

        return 0;
    } else {
        //	 cout << "fora\n";
        string s1 = " O>";
        string s2 = "<| ";
        string s3 = "/ >";

        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;

        return 0;
    }

    return 0;
}
