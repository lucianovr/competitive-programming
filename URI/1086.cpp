#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
map<int, int> mapa; // Global
int CLUBE(int H, int C, float L);

int main() {
    int m, n, k, tam, i, ret1 = -3, ret2 = -3;
    float l;

    while (cin >> m >> n && m + n) {
        mapa.clear();
        mapa[0] = 1000000;
        cin >> l;
        cin >> k;
        for (i = 0; i < k; i++) {
            cin >> tam;
            mapa[tam]++;
        }
        ret1 = CLUBE(m, n, l);
        ret2 = CLUBE(n, m, l);
        if (ret1 == -1 && ret2 == -1)
            cout << "impossivel\n";
        else if (ret1 == -1)
            cout << ret2 << endl;
        else if (ret2 == -1)
            cout << ret1 << endl;
        else
            cout << min(ret1, ret2) << endl;
    }
    return 0;
}

int CLUBE(int H, int C, float L) {

    map<int, int> mad(mapa);
    float resto;
    int div, j = 0, ct = 0, cd = 0;

    resto = (C * 100) / (int)L - ((float)C * 100.00) / L;
    if (resto != 0) {
        return -1;
    }

    div = (C * 100) / (int)L;

    while (j <= H && cd < div) {
        while (cd < div && mad[H] > 0) {
            mad[H]--;
            if (mad[j] > 0) {
                cd++;
                if (j > 0)
                    ct += 2;
                else if (j == 0)
                    ct++;
                mad[j]--;
            } else
                break;
        }
        j++;
        H--;
    }
    if (cd == div)
        return ct;
    else if (j > H)
        return -1;
}