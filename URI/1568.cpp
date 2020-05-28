#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (0)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

const int lim = 3e7 + 1;

bitset<lim> bs;
vector<long long> primes;

void get_primes() {
    bs.set();

    for (long long i = 4; i < lim; i += 2)
        bs.reset(i);

    primes.pb(2);
    for (long long i = 3; i < lim; i += 2)
        if (bs.test(i)) {
            D(i);
            for (long long j = i * i; j < lim; j += i) {
                D(j);
                bs.reset(j);
            }
            primes.pb(i);
        }
}

long long p[1000], e[1000];
int q;
void process(long long N) {
    q = 0;
    int idx = 0;
    long long primo = primes[idx++];

    while (N > 1 && primo * primo <= N) {
        if (N % primo == 0) {
            p[q] = primo;
            e[q] = 0;
            while (N % primo == 0) {
                e[q]++;
                N /= primo;
            }
            q++;
        }
        primo = primes[idx++];
    }
    if (N > 1) {
        p[q] = N;
        e[q] = 1;
        q++;
    }
}

int main() {
    get_primes();

    long long n;
    while (scanf("%lld", &n) == 1) {

        process(n);

        long long ans = 1;

        for (int i = (p[0] == 2 ? 1 : 0); i < q; i++) {
            ans = ans * (e[i] + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
