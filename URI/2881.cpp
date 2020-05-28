#include <bits/stdc++.h>
using namespace std;

int pd[1 << 10][1001];

vector<pair<pair<int, int>, pair<int, int>>> vec;

int proximo[1001];
int INF = 0x3f3f3f3f;
int n;

int f(int m, int i) {
    if (i == vec.size()) {
        if (m == ((1 << n) - 1))
            return 0;
        else
            return -INF;
    }

    int &ret = pd[m][i];
    if (ret != -1)
        return ret;
    ret = f(m, i + 1);

    int palco = vec[i].second.second;
    int musicas = vec[i].second.first;

    ret = max(ret, f(m | (1 << palco), proximo[i]) + musicas);

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int mi;
        int ini, fim, o;
        scanf("%d", &mi);
        while (mi--) {
            scanf("%d %d %d", &ini, &fim, &o);
            vec.push_back({{ini, fim}, {o, i}});
        }
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        int prim_ini = vec[i].first.second;
        int j = lower_bound(vec.begin(), vec.end(), make_pair(make_pair(prim_ini, -INF),
                    make_pair(-INF, -INF))) - vec.begin();
        proximo[i] = j;
    }

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < vec.size(); j++)
            pd[i][j] = -1;

    int ret = f(0, 0);
    if (ret < 0)
        ret = -1;
    printf("%d\n", ret);

    return 0;
}
