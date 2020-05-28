#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

#define print_array(arr)                                                                                               \
    rep(j, sizeof(arr) / sizeof(arr[0])) {                                                                             \
        if (j)                                                                                                         \
            cout << " ";                                                                                               \
        cout << arr[j];                                                                                                \
    }                                                                                                                  \
    cout << endl;

#define print_matrix(mat) rep(i, sizeof(mat) / sizeof(mat[0])){print_array(mat[i])};

const int INF = 0x3f3f3f3f;

pair<double, double> Pos[300];
int Tap[300];
const double vel = 30.0;
double PD[12][12][300];
int ID[300];

int N; // size string
string s;

double Dist(pair<double, double> a, pair<double, double> b) {
    double dx, dy;
    dx = (a.first - b.first) * (a.first - b.first);
    dy = (a.second - b.second) * (a.second - b.second);

    return sqrt(dx + dy);
}

double solve(int e, int d, int i) {
    if (i >= N)
        return 0.0;
    if (PD[e][d][i] >= 0.0)
        return PD[e][d][i];

    double t1, t2, dist1, dist2;

    dist1 = Dist(Pos[e], Pos[ID[s[i]]]);
    dist2 = Dist(Pos[d], Pos[ID[s[i]]]);

    t1 = dist1 / vel + 0.2 * Tap[s[i]];

    t2 = dist2 / vel + 0.2 * Tap[s[i]];

    double res1, res2;

    res1 = solve(ID[s[i]], d, i + 1) + t1;
    res2 = solve(e, ID[s[i]], i + 1) + t2;

    return PD[e][d][i] = min(res1, res2);
}

int main() {

    Pos[2] = make_pair(1, 3);
    Tap['a'] = 1;
    Tap['b'] = 2;
    Tap['c'] = 3;

    Pos[3] = make_pair(2, 3);
    Tap['d'] = 1;
    Tap['e'] = 2;
    Tap['f'] = 3;

    Pos[4] = make_pair(0, 2);
    Tap['g'] = 1;
    Tap['h'] = 2;
    Tap['i'] = 3;

    Pos[5] = make_pair(1, 2);
    Tap['j'] = 1;
    Tap['k'] = 2;
    Tap['l'] = 3;

    Pos[6] = make_pair(2, 2);
    Tap['m'] = 1;
    Tap['n'] = 2;
    Tap['o'] = 3;

    Pos[7] = make_pair(0, 1);
    Tap['p'] = 1;
    Tap['q'] = 2;
    Tap['r'] = 3;
    Tap['s'] = 4;

    Pos[8] = make_pair(1, 1);
    Tap['t'] = 1;
    Tap['u'] = 2;
    Tap['v'] = 3;

    Pos[9] = make_pair(2, 1);
    Tap['w'] = 1;
    Tap['x'] = 2;
    Tap['y'] = 3;
    Tap['z'] = 4;

    Pos[10] = make_pair(1, 0);
    Tap[' '] = 1;

    Pos[11] = make_pair(2, 0);
    Tap['#'] = 1;

    ID['a'] = ID['b'] = ID['c'] = 2;
    ID['d'] = ID['e'] = ID['f'] = 3;
    ID['g'] = ID['h'] = ID['i'] = 4;
    ID['j'] = ID['k'] = ID['l'] = 5;
    ID['m'] = ID['n'] = ID['o'] = 6;
    ID['p'] = ID['q'] = ID['r'] = ID['s'] = 7;
    ID['t'] = ID['u'] = ID['v'] = 8;
    ID['w'] = ID['x'] = ID['y'] = ID['z'] = 9;
    ID[' '] = 10;
    ID['#'] = 11;

    string in;
    while (getline(cin, in)) {

        int size = in.size();
        s.clear();

        s += in[0];

        for (int i = 1; i < size; i++) {
            if (ID[in[i]] == ID[in[i - 1]])
                s += '#';
            s += in[i];
        }

        N = s.size();

        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++)
                for (int k = 0; k <= N; k++)
                    PD[i][j][k] = -1.0;

        // 		 cout << Dist( Pos[ID['g']] ,  Pos[ ID['b']]) << endl;

        double ret = solve(4, 6, 0);
        printf("%0.2lf\n", ret);
    }

    return 0;
}
