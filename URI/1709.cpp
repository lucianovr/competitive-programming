#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define clear(v) memset(v, 0, sizeof v)
#define initpd(v) memset(v, -1, sizeof v)
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int pos[200010]; // esse vetor indica para onde que a carta da posicao i vai
// next_i = pos[i]

int main() {
    int n, j, idx, ans;

    scanf("%d", &n);
    j = 1;
    for (int i = 0; i < n / 2; i++) {
        pos[i] = j;
        j += 2;
    }
    j = 0;
    for (int i = n / 2; i < n; i++) {
        pos[i] = j;
        j += 2;
    }

    idx = pos[0]; // inicio com a primeira carta ja na sua proxima posicao
    ans = 1;
    while (idx != 0) { // vou simulando os passos do algoritmo at? a carta voltar pra sua posicao inicial
        idx = pos[idx];
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}