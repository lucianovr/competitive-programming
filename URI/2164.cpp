#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

double binet(int n) {
    double r5 = sqrt(5);
    double fib = (pow((1 + r5) / 2.0, (double(n))) - pow((1 - r5) / 2.0, (double(n)))) / r5;
    return fib;
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    printf("%.1lf\n", binet(n));

    return 0;
}
