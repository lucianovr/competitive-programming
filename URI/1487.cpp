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

int main() {
    int n, tempo, inst = 1;

    while (cin >> n >> tempo && n + tempo) {
        int duracao[n], pontos[n];
        rep(i, n) cin >> duracao[i] >> pontos[i];

        vi pd(tempo + 1, 0);

        for (int i = 1; i <= tempo; i++) {
            rep(j, n) {
                if (i - duracao[j] >= 0)
                    pd[i] = max(pd[i], pd[i - duracao[j]] + pontos[j]);
            }
        }
        cout << "Instancia " << inst++ << "\n";
        cout << pd[tempo] << "\n\n";
    }
    return 0;
}
