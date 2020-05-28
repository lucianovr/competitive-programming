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

string s;

void process(int a, int b) {
    if (a >= 0 && b < s.size())
        s[a] = 'J';
    s[b] = 'i';
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string f = "oulupukk";

    while (N--) {
        s.clear();
        getline(cin, s);
        int r = -1;
        while (r = s.find(f, r + 1)) {
            if (r == -1)
                break;
            process(r - 1, r + 8);
        }
        cout << s << "\n";
    }
    return 0;
}
