#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair
#define ll long long

pair<int, int> vec[] = {mk(2, 0),           mk(3, 1),           mk(5, 2),           mk(11, 4),
                        mk(29, 6),          mk(97, 8),          mk(127, 14),        mk(541, 18),
                        mk(907, 20),        mk(1151, 22),       mk(1361, 34),       mk(9587, 36),
                        mk(15727, 44),      mk(19661, 52),      mk(31469, 72),      mk(156007, 86),
                        mk(360749, 96),     mk(370373, 112),    mk(492227, 114),    mk(1349651, 118),
                        mk(1357333, 132),   mk(2010881, 148),   mk(4652507, 154),   mk(17051887, 180),
                        mk(20831533, 210),  mk(47326913, 220),  mk(122164969, 222), mk(189695893, 234),
                        mk(191913031, 248), mk(387096383, 250), mk(436273291, 282), mk(1000000000, 282)};
int tam = 32;

struct query {
    int n;
    int i;
    bool operator<(const query q) const { return n < q.n; }
};

int main() {
    int N;
    vector<query> Q;
    query aux;

    int cnt = 0;
    while (scanf("%d", &N) == 1) {
        int pos = lower_bound(vec, vec + tam, mk(N, -1)) - vec;
        if (vec[pos].first > N)
            pos--;
        printf("%d\n", vec[pos].second);
        // aux.n = N;
        // aux.i = cnt++;
        // Q.push_back(aux);
    }
    return 0;

    sort(Q.begin(), Q.end());

    vector<int> resp(Q.size());
    int pos = 0;
    for (auto q : Q) {
        while (vec[pos].first < q.n)
            pos++;
        if (vec[pos].first > q.n)
            resp[q.i] = vec[pos - 1].second;
        else
            resp[q.i] = vec[pos].second;
    }
    rep(i, 0, Q.size()) printf("%d\n", resp[i]);

    return 0;
}