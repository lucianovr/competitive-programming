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
const double EPS = 1e-9;

int main() {

    int N;
    scanf("%d", &N);
    string jA, jB, opcaoA, opcaoB;
    int opA, opB;
    ll A, B, S;

    while (N--) {
        cin >> jA >> opcaoA >> jB >> opcaoB;
        cin >> A >> B;
        S = A + B;
        if (opcaoA == "PAR") {
            opA = 0;
            opB = 1;
        } else {
            opA = 1;
            opB = 0;
        }

        if (S % 2 == opA)
            cout << jA << "\n";
        else
            cout << jB << "\n";
    }

    return 0;
}
