#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back

int main() {
    double a, b, c;
    double t = (1.0 / 3.0);
    while (cin >> a >> b >> c && a + b + c) {
        double vol = a * b * c;
        int x = pow((vol), t) + 1;

        if (x * x * x == a * b * c)
            cout << x << endl;
        else
            cout << x - 1 << endl;
    }
    return 0;
}