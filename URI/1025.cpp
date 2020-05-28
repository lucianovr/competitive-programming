#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

int busca_binaria(int v[], int inicio, int fim, int x) {
    int meio, a;
    while (!(inicio > fim)) {
        meio = (int)(inicio + fim) / 2;

        if (v[meio] == x) { // se encontrar x, farei um for do inicio ate o meio
            for (a = inicio; a <= meio; a++)
                if (v[a] == x)
                    return a + 1;
            return meio + 1;
        } else if (x < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1;
}
int compar(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
    int N, Q, pos, i, X, caso = 1; // X = num procurado , pos = pos de X

    while (cin >> N >> Q && (N + Q)) {
        int n[N], q[Q];

        for (i = 0; i < N; i++)
            cin >> n[i];
        qsort(n, N, sizeof(int), compar);

        for (i = 0; i < Q; i++)
            cin >> q[i];

        cout << "CASE# " << caso << ":\n";
        caso++;
        for (i = 0; i < Q; i++) {
            X = q[i];
            pos = busca_binaria(n, 0, N - 1, X);
            if (pos == -1)
                cout << q[i] << " not found\n";
            else
                cout << q[i] << " found at " << pos << endl;
        }

    } // while

    // system("PAUSE");
    return 0;
}
