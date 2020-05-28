#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

char B[30010], IN[MAX], C[MAX];
int P, I, J;
int INsize, Csize, abre[MAX], fecha[MAX], ok[300];
;

void EXECUTE(char op);
void SOLVE();
int LOOP(int K);

int main() {
    char aux[MAX];
    char comandos[] = {"<>-+.,#[]"};
    for (int i = 0; i < 9; i++)
        ok[comandos[i]] = 1;
    int casos;

    scanf("%d", &casos);

    for (int c = 0; c < casos; c++) {

        scanf("%s", IN);
        INsize = strlen(IN);
        scanf("%s", aux);
        int sz = strlen(aux);

        J = 0;
        for (int i = 0; i < sz; ++i)
            if (ok[aux[i]])
                C[J++] = aux[i];
        C[J] = '\0';
        Csize = strlen(C);

        stack<int> pilha;
        for (int i = 0; i < Csize; i++)
            if (C[i] == '[')
                pilha.push(i);
            else if (C[i] == ']') {
                abre[i] = pilha.top();
                fecha[pilha.top()] = i;
                pilha.pop();
            }
        P = I = J = 0;
        printf("Instancia %d\n", c + 1);
        SOLVE();
        printf("\n");
        printf("\n");

        memset(B, 0, sizeof B);
    }
}

void EXECUTE(char op) {
    switch (op) {
    case '>':
        P++;
        break;
    case '<':
        P--;
        break;
    case '+':
        B[P]++;
        break;
    case '-':
        B[P]--;
        break;
    case '.':
        cout << (char)B[P];
        break;
    case ',':
        B[P] = (I < INsize ? IN[I++] : 0);
        break;
    case '#':
        for (int k = 0; k < 10; k++)
            cout << (char)B[k];
    }
}

void SOLVE() {
    for (; J < Csize;) {
        if (C[J] == '[') {
            if (B[P] == 0)
                J = fecha[J] + 1;
            else
                J = LOOP(J + 1);
        } else
            EXECUTE(C[J++]);
    }
}

int LOOP(int K) {
    for (; true;) {
        if (C[K] == '[') {
            if (B[P] == 0)
                K = fecha[K] + 1;
            else
                K = LOOP(K + 1);
        } else if (C[K] == ']') {
            if (B[P] == 0)
                return K + 1;
            else
                K = abre[K] + 1;
        } else
            EXECUTE(C[K++]);
    }
}