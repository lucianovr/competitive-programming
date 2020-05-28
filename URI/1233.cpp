// Estrela - Sub Regional 2012
// Nao submetido

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes;           // compact list of primes in form of vector<int>

void sieve(ll upperbound) {       // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set();                     // set all bits to 1
    bs[0] = bs[1] = 0;            // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); // also add this vector containing list of primes
        }
} // call this method in main method

ll EulerPhi(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N; // start from ans = N
    while (N != 1 && (PF * PF <= N)) {
        if (N % PF == 0)
            ans -= ans / PF; // only count unique factor
        while (N % PF == 0)
            N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans -= ans / N; // last factor
    return ans;
}

int main() {
    sieve(100000);
    ll n;
    while (cin >> n) {
        ll ret = EulerPhi(n);
        cout << ret / 2 << "\n";
    }

    return 0;
}
