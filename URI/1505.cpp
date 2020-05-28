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
#define MAX 5001

int main() {
    int n, c[MAX], g[MAX], a[MAX], d[MAX], e, p, resp, cont;

    while (cin >> n) {
        rep(i, n) cin >> g[i];
        rep(i, n) cin >> c[i];
        rep(i, n) cin >> a[i];
        resp = 0;
        rep(i, n) {
            p = e = i;
            cont = 0;
            d[p] = 0;
            while (d[p] < a[p]) {
                d[p] += c[e];
                e = g[e];
                cont++;
            }
            resp = max(resp, cont);
        }

        cout << resp << endl;
    }
    return 0;
}
