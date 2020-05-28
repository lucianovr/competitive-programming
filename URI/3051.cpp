#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 500000 + 10
int N, K;

ll vet[MAXN];
ll sum[MAXN];

ll get(int a) { return sum[a]; }

ll get(int a, int b) { return get(b) - get(a - 1); }

void build() {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N + 1; i++)
        sum[i] = sum[i - 1] + vet[i];

    for (int i = 0; i <= N; i++) {
        // cout << i << " " << sum[i] << endl;
    }
}

/*
10 5
1 1 3 0 0 2 0 2 1 9
*/

int main(int argc, char **argv) {
    scanf("%d %d", &N, &K);
    vet[0] = 0;
    vet[N + 1] = 10000000;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &vet[i]);
    }

    build();

    int i = 1;
    int j = 1;
    int k = 1;
    ll ans = 0;
    for (i = 1; i <= N; i++) {

        if (j < i)
            j = i;
        while (get(i, j) < K)
            j++;
        if (k < j)
            k = j;
        while (get(i, k) <= K)
            k++;

        k = k - 1;
        if (i <= N && j <= N && k <= N && get(i, j) == K) {
            /*
            printf("(%d, %d, %d)\n", i, j, k);
            ll sumIJ = get(i,j);
            ll sumIK = get(i,k);
            ll sumJK = get(j,k);
            printf("(%d, %d, %d)\n", i, j, k);
            printf(" get(i,j) = %lld,  get(i,k) = %lld, get(j,k) = %lld\n\n", sumIJ, sumIK, sumJK );
            */
            ans += (k - j + 1);
        }
    }
    printf("%lld\n", ans);

    return 0;
}