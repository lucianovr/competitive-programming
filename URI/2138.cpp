#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif

    string s;
    while (cin >> s) {
        int cont[10] = {0};
        int sz = s.size();
        rep(i, 0, sz) cont[s[i] - '0']++;
        int n = -1, ma = 0;
        for (int i = 9; i >= 0; i--)
            if (cont[i] > ma) {
                ma = cont[i];
                n = i;
            }
        cout << n << "\n";
    }
    return 0;
}
