#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef pair<int, int> evento;
#define inicio first
#define fim second

bool compare(evento A, evento B) { return A.fim < B.fim; }

int main() {
    int n;
    cin >> n;
    vector<evento> E(n);

    rep(i, 0, n) cin >> E[i].inicio >> E[i].fim;

    sort(E.begin(), E.end(), compare);

    int cont = 1, last = 0;
    for (int i = 1; i < n; i++) {
        if (E[i].inicio >= E[last].fim) {
            last = i;
            cont++;
        }
    }

    cout << cont << "\n";

    return 0;
}
