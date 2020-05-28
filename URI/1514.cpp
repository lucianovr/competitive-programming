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

int main() {
    int n, m, x;
    int jog[110], prob[110];

    int c1, c2, c3, c4;
    while (cin >> n >> m && n + m) {
        setar(jog, 0);
        setar(prob, 0);
        c1 = c2 = c3 = c4 = 1;
        rep(i, n) {
            rep(j, m) {
                cin >> x;
                prob[j] += x;
                jog[i] += x;
            }
        }

        rep(i, n) {
            if (jog[i] == m)
                c1 = 0;
            if (jog[i] == 0)
                c4 = 0;
        }

        rep(i, m) {
            if (prob[i] == 0)
                c2 = 0;
            if (prob[i] == n)
                c3 = 0;
        }

        cout << c1 + c2 + c3 + c4 << endl;
    }
    return 0;
}
