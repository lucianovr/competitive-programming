#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

string a, b;

bool func(int m) {
    int x = 0;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            x++;
            if (x == m)
                x = 0, j++;
        }
        i++;
    }
    if (i == a.size() && j != b.size())
        return 0;
    else if (j == b.size())
        return 1;
}

int solve() {
    int resp = 0;
    int lo = 1, hi = a.size();

    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (func(m)) {
            resp = max(resp, m);
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    return resp;
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> a >> b;
        cout << solve() << "\n";
    }
    return 0;
}