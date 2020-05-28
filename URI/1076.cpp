#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
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
    int t, n;
    int u, v;
    set<ii> s;
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> u >> v;
        int x, y;
        while (v--) {
            cin >> x >> y;
            if (x < y)
                s.insert(ii(x, y));
            else
                s.insert(ii(y, x));
        }

        cout << s.sz * 2 << endl;
        s.clear();
    }
    return 0;
}
