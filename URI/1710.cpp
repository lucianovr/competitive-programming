#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

struct plane {
    int a, b, c, d;
};

plane P[510];
int M; // planos
int N; // pontos
vector<int> dir[10010];

int main() {
    while (cin >> M >> N) {
        rep(i, 0, M) {
            cin >> P[i].a >> P[i].b >> P[i].c >> P[i].d;
            dir[i].clear();
        }

        int x, y, z;
        rep(i, 0, N) {
            cin >> x >> y >> z;
            rep(j, 0, M) { dir[i].pb(P[j].a * x + P[j].b * y + P[j].c * z - P[j].d > 0); }
        }

        sort(dir, dir + N);

        int atual = 1, resp = min(1, N);
        rep(i, 1, N) {
            if (dir[i] == dir[i - 1]) {
                atual++;
                resp = max(resp, atual);
            } else {
                atual = 1;
            }
        }
        cout << resp << "\n";
    }
    return 0;
}