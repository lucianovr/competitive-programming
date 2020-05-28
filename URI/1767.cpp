#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debgu(x) cout << #x << " = " << x;
#define nl cout << "\n";
#define MAXP 50 + 5
#define MAXI 100 + 5
#define peso first
#define valor second

int pd[MAXP][MAXI], usado[MAXP][MAXI], n, PESO, CONT;
vector<pair<int, int>> item;

int solve(int s, int i) {
    if (i == n)
        return 0;
    if (pd[s][i] != -1)
        return pd[s][i];

    int ret1, ret2;
    ret1 = ret2 = 0;

    if (s - item[i].peso >= 0)
        ret2 = solve(s - item[i].peso, i + 1) + item[i].valor;
    ret1 = solve(s, i + 1);

    if (ret2 > ret1)
        usado[s][i] = 1;

    return pd[s][i] = max(ret1, ret2);
}

void back(int s, int i) {
    if (i == n || s < 0)
        return;

    if (usado[s][i] == 1) {
        CONT++;
        PESO += item[i].peso;
        back(s - item[i].peso, i + 1);
    } else
        back(s, i + 1);
}

bool compare(pair<int, int> A, pair<int, int> B) {

    if (A.valor < B.valor)
        return true;
    if (A.valor > B.valor)
        return false;
    return A.peso > B.peso;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--) {
        cin >> n;

        item.resize(n);
        PESO = CONT = 0;
        for (int i = 0; i < n; i++)
            cin >> item[i].valor >> item[i].peso;
        sort(item.begin(), item.end(), compare);

        memset(pd, -1, sizeof pd);
        memset(usado, 0, sizeof usado);

        int tot = solve(50, 0);
        back(50, 0);

        cout << tot << " brinquedos\n";
        cout << "Peso: " << PESO << " kg\n";
        cout << "sobra(m) " << n - CONT << " pacote(s)\n\n";
    }
    return 0;
}
