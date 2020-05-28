#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())

int main() {
    int n, x;
    while (cin >> n && n) {
        map<int, int> mp;
        vi v;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            v.pb(x);
            mp[x] = i;
        }
        sort(all(v));
        cout << mp[v[n - 2]] << endl;
    }
    return 0;
}
