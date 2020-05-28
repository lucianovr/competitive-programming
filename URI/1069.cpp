#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
stack<char> D;
stack<char> A;
char c[1010], a = '>', d = '<';
int i, t, n, N, cont;

void FUNC() {
    if (D.empty()) {
        cout << cont << "\n";
        return;
    }
    if ((A.empty() && !D.empty()) || (A.top() != a || D.top() != d)) {
        A.push(D.top());
        D.pop();
        FUNC();
    }
    if (A.top() == '>' && D.top() == '<') {
        A.pop();
        D.pop();
        cont++;
        FUNC();
    }
}

int main() {
    cin >> N;
    scanf("\n");
    for (n = 0; n < N; n++) {
        cin.getline(c, 1010);
        t = strlen(c);
        while (!D.empty())
            D.pop();
        while (!A.empty())
            A.pop();

        for (i = 0; i < t; i++)
            if (c[i] == a || c[i] == d)
                D.push(c[i]);

        cont = 0;

        while (!D.empty()) {
            if ((A.empty() && !D.empty()) || (A.top() != a || D.top() != d)) {
                A.push(D.top());
                D.pop();
            }
            if (!D.empty() && A.top() == '>' && D.top() == '<') {
                A.pop();
                D.pop();
                cont++;
            }
        }
        cout << cont << "\n";
    }

    // system("PAUSE");
    return 0;
}
