#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, g, a, b, i, j, vet[100001], pts, emp;

    while (cin >> n >> g) {
        pts = i = emp = 0;
        while (n--) {
            cin >> a >> b;
            if (a > b)
                pts += 3;
            else {
                vet[i++] = b - a;
                if (a == b)
                    emp++;
            }
        }
        sort(vet, vet + i);

        if (g == 0)
            cout << pts + emp << "\n";
        else {
            for (j = 0; j < i; j++) {
                if (g > vet[j]) {
                    g = g - vet[j] - 1;
                    pts += 3;
                } else if (g == vet[j]) {
                    pts++;
                    g = g - vet[j];
                }
            }
            cout << pts << "\n";
        }
    }

    return 0;
}
