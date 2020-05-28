#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c)                                                                                                      \
    sort(all(c));                                                                                                      \
    (c).resize(unique(all(c)) - c.begin());
#define PI 3.1415926535897932384626433832795028841971

typedef unsigned long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
//(-1: x<y) (0: x==y) (1: x>y)
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

string toBin(ll d) {
    string s;
    while (d) {
        s += (d & 1 ? "1" : "0");
        d /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

ll converte(string s) {
    ll id = 0;
    if (s.size() > 3) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.')
                s[i] = ' ';
        }
        stringstream ss;
        ss << s;
        ll val;
        while (ss >> val) {
            id = (id << 8) | val;
        }
    } else {
        stringstream ss;
        ss << s;
        int t;
        ss >> t;

        for (int i = 0; i < t; i++) {
            id = (id << 1) | (1);
        }
        id = id << (32 - t);
    }
    return id;
}

string formater(ll endereco) {
    string ee;
    int t = 4;
    while (t--) {
        ll val = endereco & (255LL);
        stringstream ss;
        string s;
        ss << val;
        ss >> s;
        reverse(all(s));
        ee += (s + ".");
        endereco = endereco >> 8;
    }
    ee.erase(--ee.end());
    reverse(all(ee));
    return ee;
}

void solve(ll ip, ll mask) {

    ll rede = ip & mask;

    //	cout << "rede = " << toBin(rede) << "\n";

    ll broadcast = rede | (~mask);

    //	cout << "mask = " << toBin(mask) << "\n";
    //	cout << "broad = " << toBin(broadcast) << "\n";

    ll maquinas = (1LL << (32 - __builtin_popcountll(mask))) - 2LL;
    if (maquinas < 0)
        maquinas = 0;

    cout << "Endereco de rede: " << formater(rede) << "\n";
    cout << "Endereco de broadcast: " << formater(broadcast) << "\n";
    cout << "Numero de maquinas: " << maquinas << "\n";
    cout << "\n";

    return;
}

int main() {
    string s;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;
        vector<string> v;
        while (ss >> s)
            v.pb(s);

        if (v.size() == 2) {
            solve(converte(v[0]), converte(v[1]));
        } else {
            s = v[0];
            int p = s.size() - 1;
            while (s[p] != '/')
                p--;

            string ip, mask;
            ip = s.substr(0, p);
            mask = s.substr(p + 1, 5);
            solve(converte(ip), converte(mask));
        }
    }
    return 0;
}