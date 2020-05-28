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

struct ponto {
    int x, y, z;
    ponto(){};
    ponto(int x, int y, int z) : x(x), y(y), z(z){};
    ponto operator-(ponto q) { return ponto(x - q.x, y - q.y, z - q.z); }
};

typedef ponto vetor;

int dot(vetor a, vetor b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
vetor cross(vetor a, vetor b) { return vetor(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

vector<ponto> p;
int n;

int solve() {
    int ans = min(n, 2);

    rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) {
        vetor N = cross(p[j] - p[i], p[k] - p[i]);
        if (dot(N, N) == 0)
            continue;

        int count = 0;
        rep(u, 0, n) if (dot(N, p[u] - p[i]) == 0) count++;
        ans = max(ans, count);
    }

    rep(i, 0, n) {
        int count2 = 1;
        rep(j, i + 1, n) {
            vetor M = p[j] - p[i];

            if (dot(M, M) == 0)
                count2++;
            else {
                int count = 0;
                rep(u, 0, n) {
                    vetor N = cross(M, p[u] - p[i]);
                    if (dot(N, N) == 0)
                        count++;
                }
                ans = max(ans, count);
            }
        }
        ans = max(ans, count2);
    }
    return ans;
}

int main() {
    int t;
    t = readInt();
    while (t--) {
        n = readInt();
        p.resize(n);

        rep(i, 0, n) {
            p[i].x = readInt();
            p[i].y = readInt();
            p[i].z = readInt();
        }

        int ret = solve();
        printf("%d\n", ret);
    }
    return 0;
}
