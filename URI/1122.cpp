#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

#define print_array(arr)                                                                                               \
    rep(j, sizeof(arr) / sizeof(arr[0])) {                                                                             \
        if (j)                                                                                                         \
            cout << " ";                                                                                               \
        cout << arr[j];                                                                                                \
    }                                                                                                                  \
    cout << endl;

#define print_matrix(mat) rep(i, sizeof(mat) / sizeof(mat[0])){print_array(mat[i])};

const int INF = 0x3f3f3f3f;
const int NULO = -1;
const double pi = acos(-1); // 16 casas decimais
const int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0}; // ENWS

int N, F, V[40];
int PD[40][80001];
int flag[40][2];

int solve(int i, int s) {
    if (i == N) {
        return (s == F);
    }

    if (PD[i][s + 40000] != -1)
        return PD[i][s + 40000];

    int a = solve(i + 1, s + V[i]);
    int b = solve(i + 1, s - V[i]);
    flag[i][0] |= a;
    flag[i][1] |= b;

    return PD[i][s + 40000] = (a | b);
}

int main() {

    while (cin >> N >> F && N + F) {
        int sum = 0;
        rep(i, N) {
            scanf("%d", &V[i]);
            sum += V[i];
            flag[i][0] = flag[i][1] = 0;
        }

        int inf = -sum + 40000;
        int sup = sum + 40000;

        rep(i, N) for (int j = inf; j <= sup; j++) PD[i][j] = -1;

        int ret = solve(0, 0);

        if (ret == 0)
            printf("*\n");
        else {
            for (int i = 0; i < N; i++)
                if (flag[i][0] == flag[i][1])
                    printf("?");
                else
                    printf(flag[i][0] == 1 ? "+" : "-");
            printf("\n");
        }
    }
    return 0;
}
