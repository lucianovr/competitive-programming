#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

int main() {

    int p, j1, j2, r, a;
    cin >> p >> j1 >> j2 >> r >> a;

    if (r && r == a)
        printf("Jogador 2 ganha!\n"), exit(0);
    ((j1 + j2) % 2 != p || r ^ a) ? printf("Jogador 1 ganha!\n") : printf("Jogador 2 ganha!\n");
    return 0;
}