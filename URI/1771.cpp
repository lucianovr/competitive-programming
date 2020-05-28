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

int cnt[5], mat[5][5], Min[5], Max[5];
int faixa(int num) {
    if (1 <= num && num <= 15)
        return 0;
    if (16 <= num && num <= 30)
        return 1;
    if (31 <= num && num <= 45)
        return 2;
    if (46 <= num && num <= 60)
        return 3;
    if (61 <= num && num <= 75)
        return 4;
}

string func() {
    memset(cnt, 0, sizeof cnt);
    rep(i, 0, 5) Min[i] = 100, Max[i] = 0;

    rep(i, 0, 5) rep(j, 0, 5) {
        if (i == 2 && j == 2)
            continue;
        cnt[faixa(mat[i][j])]++;
        Min[j] = min(Min[j], mat[i][j]);
        Max[j] = max(Max[j], mat[i][j]);
    }
    bool qtes = false, ordem = true;

    if (cnt[0] == 5 && cnt[1] == 5 && cnt[2] == 4 && cnt[3] == 5 && cnt[4] == 5)
        qtes = true;

    rep(j, 0, 5) {
        if (faixa(Min[j]) != j || faixa(Max[j]) != j) {
            ordem = false;
            break;
        }
    }

    if (qtes && ordem)
        return "OK";
    if (qtes && !ordem)
        return "RECICLAVEL";
    else
        return "DESCARTAVEL";
}

int main() {

    int num;
    while (cin >> mat[0][0]) {

        for (int i = 0; i < 5; i++)
            for (int j = (i == 0 ? 1 : 0); j < 5; j++) {
                if (i == 2 && j == 2)
                    continue;
                cin >> mat[i][j];
            }
        cout << func() << "\n";
    }

    return 0;
}
