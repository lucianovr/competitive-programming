#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
// se nao sobrar o num zero no globo, cond = false, e a saida ja eh NAO!
// o num zero sempre eh possivel de sair pos n-n = 0;
int main() {
    map<int, bool> mapa;
    int n, b, p;
    int i, j, v[100]; // indices
    bool cond;

    while (cin >> n >> b && n + b) {
        mapa.clear();
        cond = false;
        for (i = 0; i < b; i++) {
            cin >> v[i];
            if (v[i] == 0)
                cond = true;
        }
        if (cond) {
            for (i = 0; i < b - 1; i++) {
                p = v[i];
                for (j = i + 1; j < b; j++)
                    mapa[abs(p - v[j])] = true;
            }
            if (mapa.size() == n)
                cout << "Y\n";
            else
                cout << "N\n";
        } else
            cout << "N\n";
    }
    return 0;
}