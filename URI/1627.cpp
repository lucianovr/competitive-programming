#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int at, ad, bt, bd, M, a, b, m, time;

    scanf("%d\n", &t);

    while (t--) {
        scanf("%d%d%d%d", &at, &ad, &bt, &bd);
        scanf("%d", &M);

        a = b = time = 0;
        while (1) {

            if (a == time) {
                a += ad;
                M -= at;
                if (M <= 0) {
                    cout << "Andre\n";
                    break;
                }
            }

            if (b == time) {
                b += bd;
                M -= bt;
                if (M <= 0) {
                    cout << "Beto\n";
                    break;
                }
            }

            time++;
        }
    }

    return 0;
}
