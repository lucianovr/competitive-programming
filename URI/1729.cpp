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

int main() {

    stringstream ss;
    string s;

    int N, T;
    double D;
    N = readInt();
    scanf("%lf", &D);

    while (scanf("%d", &T) == 1) {
        bool ok = true;
        double MIN = 0;

        rep(i, 0, N) {
            cin >> s;
            if (s == "-:--:--") {
                ok = false;
            }

            ss.clear();
            if (ok) {
                ss << s;
                int h, m, sec;
                char lixo;
                ss >> h >> lixo >> m >> lixo >> sec;
                MIN += (double)(h * 60 * 60 + m * 60 + sec);
            }
        }
        MIN /= 60.0;

        double min = floor(MIN / D);
        double sec = MIN / D - min;
        sec = sec * 60;
        if (cmp(sec, 59.5) > 0)
            min++, sec = 0;

        if (ok)
            printf("%3d: %.0lf:%02.0lf min/km\n", T, min, sec);
        else
            printf("%3d: -\n", T);
    }

    return 0;
}
