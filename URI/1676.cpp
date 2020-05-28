#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> V;
int b[100000];

void preprocess(int N) {
    for (int i = 0; i <= N; i++)
        b[i] = 1;

    int cont;
    for (int i = 2; i <= N; i++) {
        if (b[i] == 1) {
            V.push_back(i);
            cont = 0;
            int j = i;
            while (j <= N) {
                j++;
                if (b[j])
                    cont++;
                if (cont == i) {
                    b[j] = 0;
                    cont = 0;
                }
            }
        }
    }
}

int main() {
    preprocess(35000);
    int N;
    while (scanf("%d", &N) && N) {
        printf("%d\n", V[N - 1]);
    }

    return 0;
}
