#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    map<int, string> aluno;
    int t, n, p, a, tam, k, j, i, presenca[101];
    string nome, his;

    cin >> t;
    for (j = 0; j < t; j++) {
        aluno.clear();
        cin >> n;
        for (i = 1; i <= n; i++) {
            presenca[i] = 0;
            cin >> nome;
            aluno[i] = nome;
        }
        for (i = 1; i <= n; i++) {
            cin >> his;
            tam = his.size();
            a = tam;
            p = 0;
            for (k = 0; k < tam; k++)
                if (his[k] == 'P')
                    p++;
                else if (his[k] == 'M')
                    a--;
            presenca[i] = int(100 * p / a);
        }
        for (i = 1; i <= n; i++)
            if (presenca[i] < 75) {
                k = i;
                cout << aluno[i];
                break;
            }
        for (i = k + 1; i <= n; i++)
            if (presenca[i] < 75)
                cout << " " << aluno[i];

        cout << endl;
    }
    return 0;
}
