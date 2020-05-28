#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back
#define debug(x) cout << #x << " = " << x << "  ";
#define nl cout << "\n";

#define print_array(arr)                                                                                               \
    rep(j, sizeof(arr) / sizeof(arr[0])) {                                                                             \
        if (j)                                                                                                         \
            cout << " ";                                                                                               \
        cout << arr[j];                                                                                                \
    }                                                                                                                  \
    cout << endl;

#define print_matrix(mat) rep(i, sizeof(mat) / sizeof(mat[0])){print_array(mat[i])};

const int INF = 0x3f3f3f3f;
const int NULO = -1;
const double pi = acos(-1); // 16 casas decimais
const int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0}; // ENWS

vector<string> A, B;
int n, m;
map<pair<string, string>, bool> vis;
pair<string, string> s;

bool CasaPrefixo(string x, string y, int m) {
    for (int i = 0; i < m; i++)
        if (x[i] != y[i])
            return false;
    return true;
}

bool dfs(string a, string b) {
    if (a == b)
        return true;

    s = make_pair(a, b);
    if (vis[s] == true)
        return false;
    vis[s] = true;

    int M, lenA, lenB;
    lenA = a.size();
    lenB = b.size();

    if (lenA == 0) {
        rep(i, n) {
            a = A[i];
            lenA = a.size();

            M = min(lenA, lenB);
            if (CasaPrefixo(a, b, M)) {
                string aux;
                if (lenA > lenB) {
                    for (int i = M; i < lenA; i++)
                        aux += a[i];
                    if (dfs(aux, ""))
                        return true;
                } else {
                    for (int i = M; i < lenB; i++)
                        aux += b[i];
                    if (dfs("", aux))
                        return true;
                }
            }
        }
    }

    else if (lenB == 0) {
        rep(i, m) {
            b = B[i];
            lenB = b.size();

            M = min(lenA, lenB);
            if (CasaPrefixo(a, b, M)) {

                string aux;
                if (lenB > lenA) {
                    for (int i = M; i < lenB; i++)
                        aux += b[i];
                    if (dfs("", aux))
                        return true;
                } else {
                    for (int i = M; i < lenA; i++)
                        aux += a[i];
                    if (dfs(aux, ""))
                        return true;
                }
            }
        }
    }
    return false;
}

int main() {
    string in;
    while (cin >> n >> m) {
        A.clear();
        B.clear();
        rep(i, n) {
            cin >> in;
            A.pb(in);
        }
        rep(j, m) {
            cin >> in;
            B.pb(in);
        }
        bool achou = false;
        vis.clear();

        for (int i = 0; i < m; i++)
            if (dfs("", B[i])) {
                cout << "S";
                achou = true;
                break;
            }
        if (!achou)
            cout << "N";
        cout << "\n";
    }
    return 0;
}
