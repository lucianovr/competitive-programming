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

int main() {

    priority_queue<int> pq;
    int N;

    while (scanf("%d", &N) && N != -1) {
        vector<int> v(N + 1);
        while (!pq.empty())
            pq.pop();

        rep(i, 1, N + 1) {
            scanf(" %d", &v[i]);
            // v[i] = i;
            if (v[i] == i)
                pq.push(-i);
        }

        bool consegue = true;

        int r = N;
        while (r >= 1 && v[r] == 0)
            r--;
        if (v[r] && v[r] < r)
            consegue = false;
        //	D(r);

        while (!pq.empty() && consegue) {
            int a = -pq.top();
            //	D(a);
            pq.pop();
            v[a] = 0;
            for (int i = 1; i < a; i++) {
                v[i]++;
                if (v[i] == i)
                    pq.push(-i);
                if (v[i] > i)
                    consegue = false;
            }
        }

        rep(i, 1, N + 1) {
            if (v[i] != 0)
                consegue = false;
        }

        consegue ? printf("S\n") : printf("N\n");
    }

    return 0;
}
