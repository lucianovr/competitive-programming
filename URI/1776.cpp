#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef unsigned long long ll;
typedef vector<ll> vi;

vi primes;
ll ans;
const int upper = 100000;
int p[100010];

void find_primes() {

    for (int i = 0; i <= upper; i += 1)
        p[i] = i % 2;
    p[1] = 0;
    p[2] = 1;

    primes.pb(2);
    for (int i = 3; i <= upper; i += 2) {
        if (p[i] == 1) {
            primes.pb(i);
            for (ll j = i * i; j <= upper; j += i) {
                p[j] = 0;
            }
        }
    }
}

void factors(ll n) {
    int p = 0;
    ll primo = primes[p];
    ans = n;

    while (n > 1 && primo * primo <= n) {
        int cont = 0;
        while (n % primo == 0) {
            n /= primo;
            cont++;
        }
        if (cont % 2 == 1)
            ans *= primo;
        primo = primes[++p];
    }
    if (n > 1)
        ans *= n;
}

int main() {
    find_primes();
    int t, caso = 1;
    ll n;

    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        factors(n);
        printf("Caso #%d: %lld\n", caso++, ans);
    }
    return 0;
}
