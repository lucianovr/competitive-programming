// IntrepidClimber_URI_1751.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

#define MAXN 112345
int n, f;
vector<pair<int, int>> g[MAXN];
bool has[MAXN];
int total = 0, maior = 0;

bool dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int viz = g[u][i].first;
        has[u] |= dfs(viz);
    }
    return has[u];
}

void sol(int u, int cur_cost) {
    maior = max(maior, cur_cost);
    for (int i = 0; i < g[u].size(); i++) {
        int viz = g[u][i].first;
        int weight = g[u][i].second;
        if (has[viz]) {
            total += weight;
            sol(viz, cur_cost + weight);
        }
    }
}

int main() {
    cin >> n >> f;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
    }

    for (int i = 0; i < f; i++) {
        int l;
        cin >> l;
        has[l] = true;
    }

    dfs(1);
    sol(1, 0);

    cout << total - maior << endl;

    return 0;
}
