#include <bits/stdc++.h>
using namespace std;

map<string, int> idx;
int cont;
const int n = 6;

int g[n][n];

bool friends(int i, int j, int k) { return g[i][j] && g[i][k] && g[k][j]; }

bool enemy(int i, int j, int k) { return (g[i][j] == 0) && (g[i][k] == 0) && (g[k][j] == 0); }
int C = 0;

int main() {
    int m;
    string a, b;
    bool flag = false;
    while (cin >> m && m != -1) {

        if (flag)
            printf("\n");
        flag = true;

        vector<string> nomes;
        idx.clear();
        for (int i = 0; i < n; i++) {
            cin >> a;
            nomes.push_back(a);
        }
        for (int i = 0; i < n; i++) {
            idx[nomes[i]] = i;
        }
        memset(g, 0, sizeof g);
        while (m--) {
            cin >> a >> b;
            g[idx[a]][idx[b]] = 1;
            g[idx[b]][idx[a]] = 1;
        }
        vector<pair<vector<string>, int>> ans;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++) {
                    vector<string> tmp;
                    if (friends(i, j, k)) {
                        tmp.push_back(nomes[i]);
                        tmp.push_back(nomes[j]);
                        tmp.push_back(nomes[k]);
                        sort(tmp.begin(), tmp.end());
                        ans.push_back(make_pair(tmp, 1));
                    } else if (enemy(i, j, k)) {
                        tmp.push_back(nomes[i]);
                        tmp.push_back(nomes[j]);
                        tmp.push_back(nomes[k]);
                        sort(tmp.begin(), tmp.end());
                        ans.push_back(make_pair(tmp, 0));
                    }
                }
        sort(ans.begin(), ans.end());
        vector<string> tmp;
        int st;
        cout << "Instancia " << ++C << "\n";
        for (int i = 0; i < ans.size(); i++) {
            tmp = ans[i].first;
            st = ans[i].second;
            cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << " sao " << (st ? "amigos" : "inimigos") << "\n";
        }
    }
    return 0;
}