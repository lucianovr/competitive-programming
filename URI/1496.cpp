#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

#define MAX_N 100000 + 10
#define LOG_TWO_N 20

int L[MAX_N], R[MAX_N], N; // entrada, idx do maior a esquerda, idx do maior a direita

int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
void RMQ(int n, const vector<int> &A) {

    for (int i = 0; i < n; i++) {
        _A[i] = A[i];
        SpT[i][0] = i;
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            if (_A[SpT[i][j - 1]] < _A[SpT[i + (1 << (j - 1))][j - 1]])
                SpT[i][j] = SpT[i][j - 1];
            else
                SpT[i][j] = SpT[i + (1 << (j - 1))][j - 1];
}

int query(int i, int j) {
    int k = (int)floor(log((double)j - i + 1) / log(2.0));
    if (_A[SpT[i][k]] <= _A[SpT[j - (1 << k) + 1][k]])
        return SpT[i][k];
    else
        return SpT[j - (1 << k) + 1][k];
}

int main() {
    vector<int> a(100010);
    while (scanf("%d", &N) == 1) {

        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        RMQ(N, a);

        L[0] = -1;
        for (int i = 1; i < N; i++) {
            L[i] = i - 1;
            int p = i - 1;
            while (a[p] <= a[i]) {
                p = L[p];
                if (p == -1)
                    break;
            }
            L[i] = p;
        }

        R[N - 1] = -1;
        for (int i = N - 2; i >= 0; i--) {
            R[i] = i + 1;
            int p = i + 1;
            while (a[p] <= a[i]) {
                p = R[p];
                if (p == -1)
                    break;
            }
            R[i] = p;
        }

        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (L[i] != -1)
                if (i - L[i] == 1)
                    continue;
            if (R[i] != -1)
                if (R[i] - i == 1)
                    continue;

            int idxL, idxR;
            int DL, DR;

            if (L[i] == -1)
                idxL = i;
            else
                idxL = query(L[i] + 1, i - 1);
            if (idxL == i)
                DL = a[i];
            else
                DL = a[i] - a[idxL];

            if (R[i] == -1)
                idxR = i;
            else
                idxR = query(i + 1, R[i] - 1);
            if (idxR == i)
                DR = a[i];
            else
                DR = a[i] - a[idxR];

            DL = min(DL, DR);
            if (DL >= 150000)
                ans.pb(i + 1);
        }

        for (int i = 0; i < ans.size(); i++) {
            if (i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
