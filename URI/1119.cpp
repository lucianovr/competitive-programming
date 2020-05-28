#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
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
#define contem(s, x) (s.find(x) != s.end())

int main() {
    int n, k, m, K, M, aux;
    while (cin >> n >> k >> m && n + k + m) {
        aux = 0;
        vi v(n, 1);
        M = n - 1;
        K = 0;
        int qte = n;
        while (qte) {
            for (int i = K, cont = 0; cont < k; i = (i + 1) % n) {
                if (v[i] == 1)
                    cont++;
                K = i;
            }
            for (int i = M, cont = 0; cont < m; i = ((i - 1) % n + n) % n) {
                if (v[i] == 1)
                    cont++;
                M = i;
            }
            if (aux)
                cout << ",";
            else
                aux = 1;
            if (K != M)
                cout << setw(3) << K + 1 << setw(3) << M + 1;
            else
                cout << setw(3) << K + 1;

            v[K] = v[M] = 0;
            if (K != M)
                qte -= 2;
            else
                qte -= 1;
        }
        cout << endl;
    }
    return 0;
}
