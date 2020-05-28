#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#define f first
#define s second
using namespace std;
vector<int> v;

int BB(int tam, int x) {
    int meio, ini = 0, fim = tam - 1;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (v[meio] == x)
            return meio;
        else if (v[meio] < x)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main() {

    int n, val, s;

    while (cin >> n) {
        v.reserve(n + 3);
        v.push_back(0);
        vector<bool> marc(n + 3, false);
        for (int i = 1; i <= n; i++) {
            cin >> val;
            v.push_back(v[i - 1] + val);
        }
        s = v.back();
        int cont = 0, j, k;
        if (s % 3 == 0) {
            s /= 3;
            for (int i = 0; i < n; i++) {
                if (!marc[i]) {
                    if ((j = BB(n + 1, v[i] + s)) != -1 && (k = BB(n + 1, v[i] + s + s)) != -1) {
                        if (!marc[j] && !marc[k]) {
                            marc[i] = true;
                            marc[j] = true;
                            marc[k] = true;
                            cont++;
                        }
                    }
                }
            }
        }
        cout << cont << endl;
        v.clear();
    }
    return 0;
}
