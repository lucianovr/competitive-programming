#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debgu(x) cout << #x << " = " << x;
#define nl cout << "\n";
#define MAX 40000 + 5

int pset[MAX];
int size[MAX];

int findSet(int i) {
    if (pset[i] != i) {
        pset[i] = findSet(pset[i]);
    }
    return pset[i];
}

bool unio(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (size[a] > size[b]) {
            pset[b] = a;
            size[a] += size[b];
        } else {
            pset[a] = b;
            size[b] += size[a];
        }
        return true;
    }
    return false;
}

int main() {
    int N, M;
    int a, b, w;
    vector<pair<int, pair<int, int>>> Edges;

    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 && M == 0)
            break;

        rep(i, 0, N + 2) {
            pset[i] = i;
            size[i] = 1;
        }

        unsigned long long int ans = 0;

        Edges.clear();
        rep(i, 0, M) {
            scanf("%d %d %d", &a, &b, &w);
            Edges.push_back(make_pair(w, make_pair(a, b)));
        }
        sort(Edges.begin(), Edges.end());

        rep(i, 0, M) {
            w = Edges[i].first;
            a = Edges[i].second.first;
            b = Edges[i].second.second;

            if (unio(a, b))
                ans += w;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
