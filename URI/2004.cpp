#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define contains(s, x) (s.find(x) != s.end())

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int t;
    //      acc, max
    int food[110][2];

    scanf("%d", &t);
    while (t--) {
        rep(i, 0, 101) food[i][0] = food[i][1] = -1;

        int n;
        scanf("%d", &n); // amount of foods in the market
        while (n--) {
            int type, weight;
            scanf("%d %d", &type, &weight);
            if (weight >= 10 && weight <= 100)
                food[type][0] = max(food[type][0], weight);

            food[type][1] = max(food[type][1], weight);
        }

        int ans = 0;
        rep(i, 1, 101) {

            if (food[i][1] != -1) {
                if (food[i][0] != -1)
                    ans += food[i][0];
                else
                    ans += food[i][1];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
