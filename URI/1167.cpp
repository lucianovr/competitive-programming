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
#define contem(s, x) (s.find(x) != s.end())

int main() {
    int n;
    while (cin >> n && n) {
        vi v(n);
        vector<string> s(n);
        rep(i, n) cin >> s[i] >> v[i];

        int k, cont, i, qte = n, crianca = 0;
        k = v[0];
        while (qte) {
            cont = 0;
            i = crianca;
            if (k % 2 != 0) {
                i = (i + 1) % n;
                for (; v[i] == 0; i = (i + 1) % n) {
                }
                for (; cont < k; i = (i + 1) % n) {
                    if (v[i])
                        cont++;
                    crianca = i;
                }
            } else {
                i = ((i - 1) % n + n) % n;
                for (; v[i] == 0; i = ((i - 1) % n + n) % n) {
                }
                for (; cont < k; i = ((i - 1) % n + n) % n) {
                    if (v[i])
                        cont++;
                    crianca = i;
                }
            }
            k = v[crianca];
            v[crianca] = 0;
            qte--;
        }
        cout << "Vencedor(a): " << s[crianca] << endl;
    }
    return 0;
}
