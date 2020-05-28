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

struct kruskal {
    vector<int> pai;
    int n;
    long long int cost;

    kruskal(int _n) {
        n = _n;
        cost = 0;
        pai.resize(n + 1);
        for (int i = 1; i <= n; i++)
            pai[i] = i;
    }

    int find(int x) {
        if (x != pai[x])
            return pai[x] = find(pai[x]);
        return pai[x];
    }

    void join(int x, int y, int c) {
        x = find(x);
        y = find(y);
        if (x != y) {
            pai[x] = y;
            cost += c;
        }
    }
};

int main() {
    int N, M;
    int x, y, c;

    while (cin >> N >> M) {
        if (N == 0 && M == 0)
            break;

        vector<pair<int, pair<int, int>>> E;
        while (M--) {
            cin >> x >> y >> c;
            E.push_back(make_pair(c, make_pair(x, y)));
        }
        sort(E.begin(), E.end());
        kruskal K(N);
        for (int i = 0; i < E.size(); i++) {
            x = E[i].second.first;
            y = E[i].second.second;
            c = E[i].first;
            K.join(x, y, c);
        }
        long long int resp = -K.cost;

        kruskal K2(N);
        for (int i = E.size() - 1; i >= 0; i--) {
            x = E[i].second.first;
            y = E[i].second.second;
            c = E[i].first;
            K2.join(x, y, c);
        }
        resp += K2.cost;

        cout << resp << "\n";
    }
    return 0;
}
