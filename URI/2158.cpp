#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c)                                                                                                      \
    sort(all(c));                                                                                                      \
    (c).resize(unique(all(c)) - c.begin());
#define pi 3.1415926535897932384626433832795028841971

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
    long long FP, FH;
    long long V, F, A;
    int caso = 1;
    while (cin >> FP >> FH) {
        F = FH + FP;
        A = (FH * 6 + FP * 5) / 2;

        V = A - F + 2;
        printf("Molecula #%d.:.\nPossui %lld atomos e %lld ligacoes\n\n", caso++, V, A);
    }

    return 0;
}