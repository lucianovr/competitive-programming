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

int main() {

    double v[3], a, b, c;

    cin >> v[0] >> v[1] >> v[2];

    sort(v, v + 3);
    a = v[2];
    b = v[1];
    c = v[0];

    if (a >= b + c) {
        cout << "NAO FORMA TRIANGULO\n";
        return 0;
    }

    if (a * a == b * b + c * c) {
        cout << "TRIANGULO RETANGULO\n";
    }

    if (a * a > b * b + c * c) {
        cout << "TRIANGULO OBTUSANGULO\n";
    }

    if (a * a < b * b + c * c) {
        cout << "TRIANGULO ACUTANGULO\n";
    }

    if (a == b && a == c)
        cout << "TRIANGULO EQUILATERO\n";
    if (a == b && a != c || a == c && a != b || b == c && b != a)
        cout << "TRIANGULO ISOSCELES\n";

    return 0;
}
