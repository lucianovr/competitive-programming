#include <bits/stdc++.h>
using namespace std;

//			 0  1  2   3   4    5   6   7   8   9   10  11 12
int mes[] = {0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int mesb[] = {0, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};

bool isBissexto(int ano) {
    if (ano % 400 == 0)
        return true;
    if (ano % 4 == 0 && ano % 100 != 0)
        return true;
    return false;
}

int main() {
    for (int i = 1; i < 13; i++) {
        mes[i] += mes[i - 1];
        mesb[i] += mesb[i - 1];
    }

    int t;
    int d1, m1, a1, d2, m2, a2;
    int ans;
    scanf("%d", &t);

    while (t--) {
        scanf("%d-%d-%d %d-%d-%d", &a1, &m1, &d1, &a2, &m2, &d2);
        ans = 0;
        if (a1 > a2 || (a1 == a2 && m1 > m2) || (a1 == a2 && m1 == m2 && d1 > d2)) {
            swap(a1, a2);
            swap(m1, m2);
            swap(d1, d2);
        }
        if (a1 != a2) {
            ans = 365 - mes[m1] - d1;
            if (isBissexto(a1)) {
                if (m1 < 2 || (m1 == 2 && d1 < 29))
                    ans++;
            }

            a1++;
            while (a1 != a2) {
                ans += 365;
                if (isBissexto(a1))
                    ans++;
                a1++;
            }

            if (isBissexto(a2))
                ans += mesb[m2] + d2;
            else
                ans += mes[m2] + d2;
        }

        else {
            if (isBissexto(a1))
                ans = mesb[m2] + d2 - (mesb[m1] + d1);
            else
                ans = mes[m2] + d2 - (mes[m1] + d1);
        }

        printf("%d\n", ans);
    }

    return 0;
}