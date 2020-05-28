#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define inf 1000000000
int main() {
    int n, a, d, ano;
    map<int, string> mp;
    string p;
    int me;
    while (cin >> n && n) {
        me = inf;
        mp.clear();
        while (n--) {
            cin >> p >> a >> d;
            ano = a - d;
            mp[ano] = p;
            if (ano < me)
                me = ano;
        }
        cout << mp[me] << endl;
    }
    return 0;
}
