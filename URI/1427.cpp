#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<string, int> mp;
map<int, string> mp_;

const int inf = 0x3f3f3f3f;
int d[110][110], func[110][110];

void fw(int n) {
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) if (d[i][j] > d[i][k] + d[k][j]) {
        d[i][j] = d[i][k] + d[k][j];
        func[i][j] = func[i][k];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string name;

        mp.clear();
        mp_.clear();

        cin >> n;
        rep(i, 0, n) {
            cin >> name;
            mp[name] = i;
            mp_[i] = name;
        }

        int x;
        rep(i, 0, n) rep(j, 0, n) {
            cin >> x;
            if (x < 0)
                d[i][j] = inf;
            else
                d[i][j] = x;
            func[i][j] = j;
        }
        fw(n);
        //		rep(i,1,n){
        //			rep(j,1,n) cout << d[i][j] << "  "; cout << "\n";
        //		}

        string a, b;
        int q;
        cin >> q;
        while (q--) {
            cin >> name >> a >> b;
            int A = mp[a], B = mp[b];
            if (d[A][B] != inf) {
                cout << "Mr " << name << " to go from " << a << " to " << b << ", you will receive " << d[A][B]
                     << " euros\n";
                cout << "Path:" << a;
                for (int i = func[A][B]; i != B; i = func[i][B]) {
                    cout << " " << mp_[i];
                }
                cout << " " << mp_[B] << "\n";
            } else
                cout << "Sorry Mr " << name << " you can not go from " << a << " to " << b << "\n";
        }
    }
    return 0;
}
