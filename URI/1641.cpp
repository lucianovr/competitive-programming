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
    int R, A, B, C, cnt = 1;
    while (scanf("%d", &R) && R) {
        R *= 2;
        scanf("%d %d", &A, &B);
        C = A * A + B * B;
        R = R * R;

        printf("Pizza %d %s on the table.\n", cnt++, (C <= R ? "fits" : "does not fit"));
    }
    return 0;
}
