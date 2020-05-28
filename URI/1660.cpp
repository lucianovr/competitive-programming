#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef unsigned long long int LL;

map<LL, int> mp;
LL A, B, N;

LL func(LL X) { return (((A % N) * (((X % N) * (X % N)) % N)) % N + B % N) % N; }

int main() {
    while (scanf("%lld", &N) && N) {

        scanf("%lld %lld", &A, &B);
        mp.clear();
        LL X = 0;
        mp[X]++;

        LL cnt = 0;

        while (1) {
            X = func(X);
            mp[X]++;
            if (mp[X] == 2)
                cnt++;
            if (mp[X] == 3)
                break;
        }
        printf("%lld\n", N - cnt);
        // cout << cnt << " " << N-cnt << "\n";
    }
    return 0;
}
