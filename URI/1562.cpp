#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

#define MAXN 10010
vector<int> prox, match, in_degree;
int N;

bool toposort() {
    priority_queue<int> pq;
    rep(u, 0, N) {
        if (in_degree[u] == 0 && match[u] == -1) {
            pq.push(-u);
        }
    }

    while (!pq.empty()) {
        int u = -pq.top();
        pq.pop();

        int v = prox[u];
        if (match[v] != -1) {
            return false;
        }
        match[u] = v;
        match[v] = u;
        int w = prox[v];
        if (w != u && match[w] == -1) {
            in_degree[w]--;
            if (in_degree[w] == 0)
                pq.push(-w);
        }
    }
    return true;
}
int main() {
    while (scanf("%d", &N) == 1) {
        prox.assign(N, -1), match.assign(N, -1), in_degree.assign(N, 0);

        for (int i = 0; i < N; i++) {
            int u;
            scanf("%d", &u);
            u--;
            prox[i] = u;
            in_degree[u]++;
        }

        if (N & 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        while (toposort()) {
            int i;
            for (i = 0; i < N; i++) {
                if (match[i] == -1 && match[prox[i]] == -1) {
                    match[i] = prox[i];
                    match[prox[i]] = i;
                    in_degree[prox[prox[i]]]--;
                    break;
                }
            }
            if (i == N)
                break;
        }

        int ok = 1;
        for (int i = 0; i < N; i++) {
            if (match[i] == -1) {
                ok = 0;
                break;
            }
        }
        if (!ok)
            cout << "IMPOSSIBLE\n";
        else {
            for (int i = 0; i < N; i++) {
                if (i)
                    cout << " ";
                cout << match[i] + 1;
            }
            cout << "\n";
        }
    }

    return 0;
}