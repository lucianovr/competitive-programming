#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
    map<string, vector<string>> MP;
    MP["tesoura"].pb("papel");
    MP["tesoura"].pb("lagarto");
    MP["papel"].pb("pedra");
    MP["papel"].pb("Spock");
    MP["pedra"].pb("lagarto");
    MP["pedra"].pb("tesoura");
    MP["lagarto"].pb("Spock");
    MP["lagarto"].pb("papel");
    MP["Spock"].pb("tesoura");
    MP["Spock"].pb("pedra");
    int t;
    cin >> t;
    for (int i = 1; i < t + 1; i++) {
        string a, b;
        cin >> a >> b;
        cout << "Caso #" << i << ": ";
        if (a == b)
            cout << "De novo!\n";
        else if (find(ALL(MP[a]), b) != MP[a].end())
            cout << "Bazinga!\n";
        else if (find(ALL(MP[b]), a) != MP[b].end())
            cout << "Raj trapaceou!\n";
        else
            cout << "De novo!\n";
    }
    return 0;
}
