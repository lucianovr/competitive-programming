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

typedef long long ll;

int n;
string s;
string ans[10];
int at;

void process(int v, int h) { ans[h] += s[at++]; }

int dfs(int v = 1, int h = 0) {
    if (v > n)
        return 0;
    dfs(v * 2, h + 1);
    process(v, h);
    dfs(v * 2 + 1, h + 1);
}
int main() {
    while (cin >> n && n) {
        getchar();
        getline(cin, s);
        at = 0;
        dfs();

        string ret;
        for (int h = 9; h >= 0; h--) {
            ret = ans[h] + ret;
            ans[h] = "";
        }
        cout << ret << "\n";
    }
    return 0;
}