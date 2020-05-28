#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        sort(all(c));                                                                                                  \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
    }
#define pb push_back

#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }

#define mp make_pair
#define fst first
#define snd second

#define isONE(mask, bit) ((mask & (1<<bit))>0
#define isZERO(mask, bit) ((mask & (1<<bit))==0
#define setBIT(mask, bit) (mask | (1 << bit))
#define clearBIT(mask, bit) (mask & ~(1 << bit))
#define toogleBIT(mask, bit) (mask ^ (1 << bit))
#define LSOne(mask) (mask & (-mask))

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

// compara doubles
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

// compara inteiros
inline int cmp(int x, int y = 0) { return (x <= y) ? (x < y) ? -1 : 0 : 1; }

// direcoes  N  W  S  E  NW SW SE NE
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// knight moves
int dkx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dky[] = {1, -1, -2, -2, -1, 1, 2, 2};

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

bitset<100010> bs;
vector<int> primos;
ll limite = 100001;

void crivo() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= limite; i++) {
        if (bs[i]) {
            primos.pb((int)i);
            for (ll j = i * i; j <= limite; j += i) {
                bs[j] = 0;
            }
        }
    }
}

vector<pair<int, int>> v; // fatores primos de N! e seus respectivos expoentes
const int MOD = 1000000007;
ll fat[100010];

ll fast_pow(ll b, ll p) {
    if (p == 0)
        return 1;
    ll ret = fast_pow(b, p / 2) % MOD;
    ret = (ret * ret) % MOD;

    if (p & 1)
        ret = (ret * (b % MOD)) % MOD;
    return ret;
}

int main() {
    primos.clear();
    crivo();

    fat[0] = 1;
    for (ll i = 1; i <= 100001; i++) {
        fat[i] = (i * fat[i - 1]) % MOD;
    }

    int N;
    while (scanf("%d", &N) == 1) {

        v.clear();
        for (int i = 0; i < primos.size(); i++) {
            if (primos[i] > N)
                break;
            int exp = 0, NN;
            NN = N;
            while (NN) {
                exp += NN / primos[i];
                NN /= primos[i];
            }
            v.pb(mp(primos[i], exp));
        }

        ll soma = 1, PF, power, b, inv, temp;
        for (int i = 0; i < v.size(); i++) {
            PF = v[i].fst, power = v[i].snd;
            b = fast_pow(PF, power + 1) - 1;
            if (b < 0)
                b += MOD;

            inv = fast_pow(PF - 1, MOD - 2);
            temp = (b * inv);
            if (temp >= MOD)
                temp %= MOD;

            soma = (soma * temp);
            if (soma >= MOD)
                soma %= MOD;
        }

        soma = soma - fat[N];
        if (soma < 0)
            soma += MOD;

        printf("%lld %lld\n", soma, fat[N]);
    }
    return 0;
}
