#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    double a, b, c, d, e, m;

    while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) == 4) {
        m = (2 * a + 3 * b + 4 * c + d) / 10;
        m = (double)((int)(m * 10)) / 10;
        printf("Media: %.1lf\n", m);
        if (m >= 7.0)
            printf("Aluno aprovado.\n");
        else if (m < 5.0)
            printf("Aluno reprovado.\n");
        else {
            printf("Aluno em exame.\n");
            scanf("%lf", &e);
            printf("Nota do exame: %.1lf\n", e);
            m = (m + e) / 2;
            m = (double)((int)(m * 10)) / 10;
            if (m >= 5.0)
                printf("Aluno aprovado.\n");
            else
                printf("Aluno reprovado.\n");
            printf("Media final: %.1lf\n", m);
        }
    }
    return 0;
}
