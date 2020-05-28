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

int t, N, C, M;
int V[50010];

bool comp(int a, int b) { return a > b; }

int main() {
    int ans;

    scanf("%d", &t);

    while (t--) {
        ans = 0;
        scanf("%d %d %d", &N, &C, &M);
        rep(i, 0, M) scanf("%d", &V[i]);

        sort(V, V + M, comp);

        for (int i = 0; i < M; i += C) {
            ans += V[i];
        }

        printf("%d\n", ans << 1);
    }
    return 0;
}
