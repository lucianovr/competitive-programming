#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
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

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

// primos
bool ehprimo[1010];
vector<int> primos;
void crivo(int limite) {
    memset(ehprimo, true, sizeof ehprimo);

    ehprimo[0] = ehprimo[1] = false;

    for (int i = 2; i <= limite; i++) {
        if (ehprimo[i]) {
            primos.push_back(i);
            for (int j = i * i; j <= limite; j += i)
                ehprimo[j] = false;
        }
    }
}

// fatoracao
int p[8010], e[8010];
int fatora(int n) {
    int primo, limite, idx = 0;
    primo = primos[idx++];
    int tam = 0;
    memset(e, 0, sizeof e);
    limite = (int)sqrt(n);

    while (n > 1 && primo <= limite) {
        if (n % primo == 0) {
            p[tam] = primo;
            e[tam] = 1;
            n /= primo;
            while (n % primo == 0) {
                e[tam]++;
                n /= primo;
            }
            tam++;
        }
        primo = primos[idx++];
    }
    if (n > 1) {
        p[tam] = n;
        e[tam] = 1;
        tam++;
    }
    return tam;
}

int NumOfDigitsInFactorial(int N, int B) {
    /*	double n = (double)(N);
            double b = (double)(B);
            
            int A = floor( ((n+0.5)*log(n) - n + 0.5*log(2*M_PI))/log(b) ) + 1;
    */

    double logFatN = 0;
    for (int i = 1; i <= N; i++) {
        logFatN += log((double)i);
    }
    int nd = floor(logFatN / log((double)B)) + 1;
    return nd;
}

int NumOfTrailingZeros(int N, int B) {
    int nfact = fatora(B);
    int ans = INF;

    for (int i = 0; i < nfact; i++) {
        int soma = 0;
        int NN = N;
        while (NN / p[i] > 0) {
            soma += NN / p[i];
            NN /= p[i];
        }
        int aux = soma / e[i];
        // cout << p[i] << " " << e[i] << " " << soma << "\n";
        ans = min(ans, aux);
    }
    return ans;
}

int main() {

    int n, b;
    crivo(1000);

    while (cin >> n >> b) {

        if (n < 2) {
            cout << "0 1\n";
            continue;
        }

        int NTZ = NumOfTrailingZeros(n, b);
        int NDF = NumOfDigitsInFactorial(n, b);
        cout << NTZ << " " << NDF << "\n";
    }
    return 0;
}
