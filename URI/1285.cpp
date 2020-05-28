#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
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
int cont[10], y;

int bs(int ini, int fim, int x, vi V) {
    int me;
    while (ini <= fim) {
        me = (ini + fim) >> 1;
        if (V[me] == x)
            return me;
        else if (V[me] > x)
            fim = me - 1;
        else
            ini = me + 1;
    }
}
bool func(int x) {
    rep(i, 10) cont[i] = 0;
    while (x) {
        y = x % 10;
        if (cont[y])
            return false;
        x /= 10;
        cont[y] = 1;
    }
    return true;
}
int main() {
    vi v;

    for (int i = 1; i <= 5000; i++)
        if (func(i))
            v.pb(i);
    int n, m;
    bool flag;
    while (cin >> n >> m) {
        flag = false;
        if (!func(n)) {
            n++;
            while (!func(n)) {
                n++;
                if (n > m)
                    break;
            }
        }
        if (n > m)
            flag = true;
        else {
            if (!func(m)) {
                m--;
                while (!func(m)) {
                    m--;
                    if (n > m)
                        break;
                }
            }
        }
        if (n > m)
            flag = true;
        if (flag)
            cout << 0 << endl;
        else {
            int i = bs(0, v.sz, n, v);
            int j = bs(0, v.sz, m, v);
            cout << j - i + 1 << endl;
        }
    }
    return 0;
}
