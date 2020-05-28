#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())
vi pset, pts;

void make_set(int i) { pset[i] = i; }

int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }

int main() {
    int n, m, q, a, b;
    while (cin >> n >> m && n + m) {
        pset.resize(n + 10);
        pts.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            make_set(i);
            cin >> pts[i];
        }

        int SetA, SetB, Set1, pA, pB, cont = 0;
        while (m--) {
            cin >> q >> a >> b;
            SetA = findSet(a);
            SetB = findSet(b);
            Set1 = findSet(1);

            if (q == 1) {
                if (SetA != SetB) {
                    pts[SetB] += pts[SetA];
                    pset[SetA] = SetB;
                }
            } else {
                pA = pts[SetA];
                pB = pts[SetB];
                if (Set1 == SetA && pA > pB)
                    cont++;
                else if (Set1 == SetB && pB > pA)
                    cont++;
            }
        }

        cout << cont << endl;
    }

    return 0;
}