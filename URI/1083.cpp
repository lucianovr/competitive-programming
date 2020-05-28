#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897932384626433832795028841971693993751058209
#define rep(a, b, n) for (int a = b; a < n; a++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << "\n";
#define Debug(x, y) cout << #x << " " << #y << " = " << y << "\n";
int pri[] = {1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6};
char op[] = {"|.><=#+-*/^"};
char EXP[10000];

vector<char> saida;
stack<char> pilha;

bool eOperador(char simb) {
    rep(i, 0, 11) if (simb == op[i]) return true;
    return false;
}

int prioridade(char simb) { rep(i, 0, 11) if (simb == op[i]) return pri[i]; }

void lexsim() {
    saida.clear();
    while (!pilha.empty())
        pilha.pop();

    if (EXP[0] == '(') {
        pilha.push('(');
        //	    debug(pilha.top());
    } else if (isalpha(EXP[0]) || isdigit(EXP[0]))
        saida.pb(EXP[0]);

    else {
        if (EXP[0] == ')')
            printf("Syntax Error!\n");
        else
            printf("Lexical Error!\n");
        return;
    }

    int size = strlen(EXP);
    for (int i = 1; i < size; i++) {

        if (EXP[i] == '(') {
            pilha.push(EXP[i]); // abre parenteses
                                //			debug(pilha.top());
        }

        else if (isalpha(EXP[i]) || isdigit(EXP[i])) // numero ou letra
        {
            if (isalpha(EXP[i - 1]) || isdigit(EXP[i - 1])) {
                printf("Syntax Error!\n");
                return;
            } else
                saida.pb(EXP[i]); // coloco na saida o operando
        } else if (EXP[i] == ')') {
            while (!pilha.empty() && pilha.top() != '(') {
                saida.pb(pilha.top());
                //                Debug("sai", pilha.top());
                pilha.pop();
            }
            if (pilha.empty()) { // nao encontrou o '('
                printf("Syntax Error!\n");
                return;
            } else {
                //            	 Debug("sai", pilha.top());
                //				 debug(pilha.top());
                pilha.pop(); // encontrou o '('
            }
        } else if (eOperador(EXP[i])) {
            if (eOperador(EXP[i - 1])) {
                printf("Syntax Error!\n");
                return;
            } else {
                int P = prioridade(EXP[i]);
                while (!pilha.empty() && eOperador(pilha.top()) && P <= prioridade(pilha.top())) {
                    saida.pb(pilha.top());
                    pilha.pop();
                }
                pilha.push(EXP[i]);
            }

        } else { // nao eh operador
            printf("Lexical Error!\n");
            return;
        }
    }

    while (!pilha.empty()) {
        if (pilha.top() == '(') {
            printf("Syntax Error!\n");
            return;
        } else {
            saida.pb(pilha.top());
            pilha.pop();
        }
    }

    size = saida.size();

    rep(i, 0, size) cout << saida[i];
    cout << "\n";
}

int main() {
    while (cin >> EXP)
        lexsim();
    return 0;
}