#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

unsigned long long soma[100010];
string names[100010];
string nome;

unsigned long long calc(string a) {
    unsigned long long sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i];
    }
    return sum;
}

int bsearch(int n) {
    int lo = 0, hi = n - 1, mid;
    unsigned long long l, r;
    int k;
    while (lo < hi) {
        mid = lo + hi >> 1;
        l = r = 0;

        k = 1;
        for (int j = mid; j >= 0; j--) {
            l += soma[j] * k;
            k++;
        }

        k = 1;
        for (int j = mid + 1; j < n; j++) {
            r += soma[j] * k;
            k++;
        }

        if (l == r)
            return mid;
        if (l < r)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return -1;
}

int main() {
    int t;

    while (cin >> t && t) {

        for (int i = 0; i < t; i++) {
            cin >> nome;
            soma[i] = calc(nome);
            names[i] = nome;
        }

        int ret = bsearch(t);
        if (ret == -1)
            cout << "Impossibilidade de empate.\n";
        else
            cout << names[ret] << endl;
    }

    return 0;
}