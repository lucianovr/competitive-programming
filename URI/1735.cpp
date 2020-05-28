#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N;
vi adj[60];
int vis[60];
int grau[60];

vi Prufer() { // cria a sequencia N-1 inteiros de prufer de uma ?rvore nao enraizada de N verticos
    vi ans;
    priority_queue<ii> Q;
    memset(vis, 0, sizeof vis);

    for (int i = 1; i <= N; i++) {
        Q.push(make_pair(-grau[i], -i));
    }

    int cont = N - 1;

    while (cont) {
        int v = -Q.top().second;
        Q.pop();
        if (vis[v])
            continue;
        cont--;
        vis[v] = 1;
        int u;
        rep(i, 0, adj[v].size()) {
            u = adj[v][i];
            if (!vis[u])
                break;
        }
        grau[u]--;
        ans.pb(u);

        Q.push(ii(-grau[u], -u));
    }
    return ans;
}

int main() {
    int val;
    stack<int> p;
    string in;

    while (getline(cin, in)) {

        N = -1;
        rep(i, 0, 60) {
            adj[i].clear();
            grau[i] = 0;
        }
        while (!p.empty())
            p.pop();
        int len = in.size();

        for (int i = 0; i < len;) {
            if (in[i] == '(') {
                val = (in[i + 1] - '0');
                i++;
                if (i + 1 < len && isdigit(in[i + 1])) {
                    val *= 10;
                    val += (in[i + 1] - '0');
                    i++; //
                }
                p.push(val);
                N = max(N, val);
            } else if (in[i] == ')') {
                if (!p.empty()) {
                    int u = p.top();
                    p.pop();
                    if (!p.empty()) {
                        int v = p.top();
                        grau[v]++;
                        grau[u]++;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                }
            }
            i++;
        }

        vi prufer = Prufer();
        rep(i, 0, prufer.size()) {
            if (i)
                printf(" ");
            printf("%d", prufer[i]);
        }
        printf("\n");
    }
    return 0;
}
