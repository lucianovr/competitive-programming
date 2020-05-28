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
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;
char comb[][7] = {"254613", "546213", "462513", "625413", "264531", "645231", "452631", "526431",
                  "163524", "635124", "351624", "516324", "153642", "536142", "361542", "615342",
                  "123456", "234156", "341256", "412356", "143265", "432165", "321465", "214365"};

int v[1010][7];

bool equals(int k) {
    int aux[7];
    rep(i, 0, k) {
        rep(c, 0, 24) {
            rep(j, 0, 6) aux[j + 1] = comb[c][j] - '0';

            if (v[i][1] == v[k][aux[1]] && v[i][2] == v[k][aux[2]] && v[i][3] == v[k][aux[3]] &&
                v[i][4] == v[k][aux[4]] && v[i][5] == v[k][aux[5]] && v[i][6] == v[k][aux[6]])
                return true;
        }
    }
    return false;
}

int main() {

    int t, n;
    while (cin >> n && n) {
        t = 0;
        scanf("%d %d %d %d %d %d", &v[0][5], &v[0][1], &v[0][2], &v[0][3], &v[0][4], &v[0][6]);

        rep(i, 1, n) {
            t++;
            scanf("%d %d %d %d %d %d", &v[t][5], &v[t][1], &v[t][2], &v[t][3], &v[t][4], &v[t][6]);
            if (equals(t) == true)
                t--;
        }

        printf("%d\n", t + 1);
    }
    return 0;
}
