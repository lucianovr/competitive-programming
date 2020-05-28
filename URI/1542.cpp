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
    int x, d, y, t;

    while (cin >> x && x) {
        cin >> d >> y;
        t = (d * x * y) / (y - x);

        cout << t;
        if (t > 1)
            cout << " paginas\n";
        else
            cout << " pagina\n";
    }
    return 0;
}
