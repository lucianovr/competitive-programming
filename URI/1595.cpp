#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;

double v[100001], r;
int s, c;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %lf", &s, &c, &r);

        rep(i, 0, s) scanf("%lf", &v[i]);

        sort(v, v + s);

        double t = 0;

        for (int i = 0; i < s; i++) {
            if (i < c)
                t += 1 / (v[i] + r);
            else
                t += 1 / v[i];
        }
        printf("%.2lf\n", t);
    }

    return 0;
}
