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
const double EPS = 1e-9;

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int BH = 0;
        int hea, mea, hsa, msa, heb, meb, hsb, msb;
        // hea (hora de entrada de manha)
        // mea (minuto de entrada de manha)
        // hsa (hora de saida de manha)
        // msa (minuto de saida de manha)
        // heb ||
        // ...
        vector<ii> h;
        rep(i, 0, n) {
            scanf("%d:%d %d:%d | %d:%d %d:%d", &hea, &mea, &hsa, &msa, &heb, &meb, &hsb, &msb);
            h.pb(ii(hea * 60 + mea, hsa * 60 + msa)); // indices pares (de manha)
            h.pb(ii(heb * 60 + meb, hsb * 60 + msb)); // indices impares (a tarde)
        }

#define CedoIN (8 * 60)
#define CedoOUT (12 * 60)

#define TardeIN (14 * 60)
#define TardeOUT (18 * 60)

#define entrada first
#define saida second
        rep(i, 0, h.size()) {
            if (i % 2 == 0) { // de manha
                if (h[i].entrada + 5 < CedoIN)
                    BH += CedoIN - h[i].entrada; // chegou antes
                if (h[i].entrada - 5 > CedoIN)
                    BH -= h[i].entrada - CedoIN; // chegou atrasado

                if (h[i].saida + 5 < CedoOUT)
                    BH -= CedoOUT - h[i].saida; // saiu antes
                if (h[i].saida - 5 > CedoOUT)
                    BH += h[i].saida - CedoOUT; // saiu depois
            } else {
                if (h[i].entrada + 5 < TardeIN)
                    BH += TardeIN - h[i].entrada; // chegou antes
                if (h[i].entrada - 5 > TardeIN)
                    BH -= h[i].entrada - TardeIN; // chegou atrasado

                if (h[i].saida + 5 < TardeOUT)
                    BH -= TardeOUT - h[i].saida; // saiu antes
                if (h[i].saida - 5 > TardeOUT)
                    BH += h[i].saida - TardeOUT; // saiu depois
            }
        }

        BH < 0 ? printf("- ") : printf("+ ");
        if (BH < 0)
            BH *= -1;

        int horas = BH / 60;
        int min = BH % 60;

        if (horas < 10)
            printf("0");
        printf("%d:", horas);
        if (min < 10)
            printf("0");
        printf("%d\n", min);
    }

    return 0;
}
