#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;

int cont;
stack<char> B, A;

bool compara() {

    if ((B.top() == 'B' && A.top() == 'S') || (B.top() == 'S' && A.top() == 'B')) {
        cont++;
        return true;
    }
    if ((B.top() == 'C' && A.top() == 'F') || (B.top() == 'F' && A.top() == 'C')) {
        cont++;
        return true;
    }
    return false;
}

int main() {

    int t, i;
    char dna[301];

    while (scanf("%s", dna) != EOF) {

        while (!B.empty())
            B.pop();
        while (!A.empty())
            A.pop();
        t = strlen(dna);

        if (t == 1)
            printf("0\n");
        else {
            for (i = 0; i < t; i++)
                B.push(dna[i]);

            cont = 0;

            while (!B.empty()) {
                if (A.empty()) {
                    A.push(B.top());
                    B.pop();
                }
                if (!B.empty() && compara()) {
                    B.pop();
                    A.pop();
                } else {
                    A.push(B.top());
                    B.pop();
                }
            }
            printf("%d\n", cont);
        }
    }

    return 0;
}
