#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define Rep(i, b) rep(i, 0, b)
#define tr(it, v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define all(v) (v.begin(), v.end())
#define pb push_back
#define contains(S, x) (S.find(x) != S.end())
#define dentro(a, b, n, m) (a >= 0 && a < n && b >= 0 && b < m)
/* printa matriz A[n][m]*/
#define printM(A, n, m)                                                                                                \
    Rep(i, n) {                                                                                                        \
        Rep(j, m) {                                                                                                    \
            cout << A[i][j];                                                                                           \
            if (j != m - 1)                                                                                            \
                cout << "#";                                                                                           \
        }                                                                                                              \
        cout << "\n";                                                                                                  \
    }

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

//              <- ^ -> v
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

int main() {

    char c;
    char line[10000];
    int size;

    scanf(" %c", &c);

    double tot, cont;

    char *pc;

    scanf("\n");
    cin.getline(line, 10000);

    tot = cont = 0;

    pc = strtok(line, " ");
    while (pc != NULL) {
        tot++;
        size = strlen(pc);
        Rep(i, size) if (pc[i] == c) {
            cont++;
            break;
        }
        pc = strtok(NULL, " ");
    }

    double resp = (cont / tot) * 100;

    cout << fixed << setprecision(1) << resp << "\n";

    return 0;
}
