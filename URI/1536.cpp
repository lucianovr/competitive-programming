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
    cin >> n;
    char x;
    while (n--) {
        int a, b, pa, pb, sa, sb, ga, gb;
        pa = pb = sa = sb = ga = gb = 0;

        cin >> a >> x >> b;
        if (a > b)
            pa += 3;
        else if (a == b) {
            pa++;
            pb++;
        } else
            pb += 3;
        sa += a - b;
        sb += b - a;
        gb = b;

        cin >> b >> x >> a;

        if (a > b)
            pa += 3;
        else if (a == b) {
            pa++;
            pb++;
        } else
            pb += 3;
        sa += a - b;
        sb += b - a;
        ga = a;

        if (pa > pb)
            cout << "Time 1\n";
        else if (pa < pb)
            cout << "Time 2\n";

        else if (pa == pb) {
            if (sa > sb)
                cout << "Time 1\n";
            else if (sa < sb)
                cout << "Time 2\n";
            else if (ga > gb)
                cout << "Time 1\n";
            else if (ga < gb)
                cout << "Time 2\n";
            else
                cout << "Penaltis\n";
        }
    }
    return 0;
}
