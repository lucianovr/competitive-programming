#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int dp[1001][1001];
int memo[1001][1001];

int sol(int i, int mod) {
    if (i == s.size())
        return (mod == 0);

    int &ret = dp[i][mod];
    if (ret != -1)
        return ret;
    ret = 0;

    if (s[i] != '?') {
        memo[i][mod] = (s[i] - '0');
        ret = sol(i + 1, (mod * 10 + (s[i] - '0')) % n);
    } else {
        for (int d = (i == 0 ? 1 : 0); d < 10; d++) {
            if (sol(i + 1, (mod * 10 + d) % n) == 1) {
                memo[i][mod] = d;
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

string ans;
void bt(int i, int mod) {
    if (i == s.size())
        return;

    ans += char(memo[i][mod] + '0');
    bt(i + 1, (mod * 10 + memo[i][mod]) % n);
}

int main() {
    while (cin >> s >> n) {
        memset(dp, -1, sizeof dp);
        // memset(memo, -1, sizeof memo);
        int ret = sol(0, 0);
        if (ret == 0)
            puts("*");
        else {
            ans.clear();
            bt(0, 0);
            printf("%s\n", ans.c_str());
        }
    }
    return 0;
}