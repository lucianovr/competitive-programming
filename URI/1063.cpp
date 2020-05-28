#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> A;
    stack<char> E;
    int n, i;
    bool av, ev;
    char vagao;
    i = 0;
    while (cin >> n && n) {
        char aux[n], s[n];

        for (i = 0; i < n; i++)
            cin >> aux[i]; // leitura
        for (i = 0; i < n; i++)
            cin >> s[i]; // ||
        while (!A.empty())
            A.pop(); // desempilhando
        while (!E.empty())
            E.pop(); // ||
        for (i = n - 1; i >= 0; i--)
            A.push(aux[i]); // empilhando
        i = 0;
        while (true) {
            vagao = s[i];
            av = !A.empty();
            ev = !E.empty();
            if (ev && vagao == E.top()) {
                cout << "R";
                i++;
                E.pop();
            } else if (av && vagao == A.top()) {
                cout << "I";
                E.push(A.top());
                A.pop();
            } else if (av) {
                while (!A.empty() && vagao != A.top()) {
                    E.push(A.top());
                    cout << "I";
                    A.pop();
                }
            } else if (!av && ev && vagao != E.top()) {
                cout << " Impossible";
                break;
            } else if (!av && !ev)
                break;
        }
        cout << "\n";
    }

    return 0;
}
