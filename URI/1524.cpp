#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool comp(int a, int b) { return a > b; }

int main() {

    int N, K, x;
    int num[1010], d[1010];
    unsigned long long sum;

    while (scanf("%d %d", &N, &K) == 2) {
        N--;
        K--;
        for (int i = 0; i < N; i++)
            scanf("%d", &num[i]);

        sum = num[N - 1];

        d[0] = num[0];
        for (int i = 1; i < N; i++)
            d[i] = num[i] - num[i - 1];

        sort(d, d + N, comp);

        for (int i = 0; i < K; i++) {
            sum -= d[i];
        }

        cout << sum << "\n";
    }

    return 0;
}