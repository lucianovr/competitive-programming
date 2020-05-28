#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    double v;
    double Ai = 0, Af = 25, Bi = 25, Bf = 50, Ci = 50, Cf = 75, Di = 75, Df = 100;

    while (scanf("%lf", &v) == 1) {
        if (v < 0 || v > 100)
            printf("Fora de intervalo\n");
        else if (v >= Ai && v <= Af)
            printf("Intervalo [0,25]\n");
        else if (v > Bi && v <= Bf)
            printf("Intervalo (25,50]\n");
        else if (v > Ci && v <= Cf)
            printf("Intervalo (50,75]\n");
        else if (v > Di && v <= Df)
            printf("Intervalo (75,100]\n");
    }
    return 0;
}
