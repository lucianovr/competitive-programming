#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define f first
#define s second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define MAX 10
#define MIN 0

double calcula(double h1, double h2, double larg) { return (((h1 + h2) * larg) / 2.0); }

int main() {

    double area, a, b, vo, v, dt, B, x, ret;
    vector<pair<double, double>> vec;
    int n;

    while (cin >> n && n) {
        B = -1.0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (i == 0)
                B = b;
            if (i > 0) {
                vec.pb(make_pair(B, a));
            }
            vec.pb(make_pair(a, b));
            B = b;
        }
        vo = area = 0.0;
        n = vec.size();
        for (int i = 0; i < n; i++) {
            a = vec[i].f;
            b = vec[i].s;
            if (i % 2 == 0) {
                v = vo + b - a;
                if (v <= MAX) {
                    ret = calcula(v, vo, b - a);
                    area += ret;
                    vo = v;
                } else {
                    x = 10.0 - vo + a;
                    ret = calcula(10.0, vo, x - a) + (b - x) * 10.0;
                    area += ret;
                    vo = 10.0;
                }
            } else {
                v = vo - 2 * (b - a);
                if (v >= MIN) {
                    ret = calcula(v, vo, b - a);
                    area += ret;
                    vo = v;
                } else {
                    x = vo / 2.0 + a;
                    ret = calcula(vo, 0.0, x - a);
                    area += ret;
                    vo = 0.0;
                }
            }
        }
        cout << fixed << setprecision(2) << area << endl;
        vec.clear();
    }
    return 0;
}
