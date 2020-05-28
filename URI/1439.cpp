#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int p, m, n, dir;
vector<pair<int, string>> pilha;
vector<pair<int, string>> jog[11];
pair<int, string> pd;

bool compare(pair<int, string> a, pair<int, string> b) {
    if (a.first > b.first)
        return true;
    if (a.first < b.first)
        return false;
    if (a.second > b.second)
        return true;
    return false;
}
int prox(int i) { return ((i + dir) % p + p) % p; }
void compra(int i) {
    jog[i].push_back(pilha[0]);
    pilha.erase(pilha.begin() + 0);
}

int procuraCarta(int i) {
    int k;
    sort(jog[i].begin(), jog[i].end(), compare);

    for (k = 0; k < jog[i].size(); k++)
        if (jog[i][k].first == pd.first || jog[i][k].second == pd.second) {
            pd = jog[i][k];
            //  cout << "jog["<<i<<"] descarta " << pd.first << " " << pd.second;
            jog[i].erase(jog[i].begin() + k);
            //  cout << "  # de cartas " << jog[i].size() << endl;
            return 1;
        }

    compra(i);
    if (jog[i].back().first == pd.first || jog[i].back().second == pd.second) {
        // cout << "e jog["<<i<<"] descarta\n";
        pd = jog[i].back();
        jog[i].erase(jog[i].begin() + jog[i].size() - 1);
        return 1;
    }

    return 0;
}

void BoraBora(int i) {

    if (jog[i].size() == 0) {
        cout << i + 1 << endl;
        return;
    }
    // cout << "\nvez de jog["<<i<<"]\n";
    if (procuraCarta(i)) {
        if (jog[i].size() == 0) {
            cout << i + 1 << endl;
            return;
        }
        if (pd.first == 12)
            dir = -dir;
        else if (pd.first == 1) {
            i = prox(i);
            compra(i);
        } else if (pd.first == 7) {
            i = prox(i);
            compra(i);
            compra(i);
        } else if (pd.first == 11) {
            i = prox(i);
        }
    }
    i = prox(i);
    BoraBora(i);
}

int main() {

    int rest, val;
    string naipe;
    while (cin >> p >> m >> n && p + n + m) {

        pilha.clear();
        for (int i = 0; i < p; i++)
            jog[i].clear();

        for (int i = 0; i < p; i++)
            for (int k = 0; k < m; k++) {
                cin >> val >> naipe;
                jog[i].push_back(make_pair(val, naipe));
            }
        cin >> val >> naipe;
        pd = make_pair(val, naipe);
        rest = n - (p * m + 1);
        for (int i = 0; i < rest; i++) {
            cin >> val >> naipe;
            pilha.push_back(make_pair(val, naipe));
        }
        dir = 1;
        if (pd.first == 12) {
            dir = -1;
            BoraBora(0);
        } else if (pd.first == 11)
            BoraBora(1);
        else if (pd.first == 1) {
            compra(0);
            BoraBora(1);
        } else if (pd.first == 7) {
            compra(0);
            compra(0);
            BoraBora(1);
        } else
            BoraBora(0);
    }

    return 0;
}
