#include <algorithm>
#include <cmath> // atan2(dy,dx) :retorna angulo polar
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility> // #define x first , y second  quando trabalhar com pontos
#include <vector>  // #include <map> , <set> , <stack> , <queue> , <deque>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

int quad(int x) { return x * x; }

int rafael(int x, int y) { return (quad(3 * x) + quad(y)); }

int beto(int x, int y) { return (2 * (quad(x)) + quad(5 * y)); }

int carlos(int x, int y) { return (-100 * x + y * y * y); }

int main() {
    int t;

    cin >> t;
    while (t--) {
        int X, Y;
        int r, b, c;
        cin >> X >> Y;
        r = rafael(X, Y);
        b = beto(X, Y);
        c = carlos(X, Y);

        if (r > c && r > b)
            cout << "Rafael ganhou\n";

        if (b > r && b > c)
            cout << "Beto ganhou\n";

        if (c > r && c > b)
            cout << "Carlos ganhou\n";
    }

    return 0;
}
