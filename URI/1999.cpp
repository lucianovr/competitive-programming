#include <iostream>
using namespace std;

int main() {

    long long N;
    int ans = 0;
    long long A, B, C;

    while (scanf("%lld", &N) && N != -1) {
        for (A = N; A >= 1; A--) {
            for (B = min(A, N / A); B >= 1; B--) {
                C = min(B, (N - A * B) / (A + B));
                if (A * B + A * C + B * C == N) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        ans = 0;
    }
    return 0;
}
