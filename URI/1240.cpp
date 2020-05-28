#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

bool encaixa(string A, string B) {
    long long int tam1 = A.size(), tam2 = B.size();

    if (tam1 < tam2)
        return false;
    else {
        for (int i = tam2 - 1; i >= 0; i--) {
            if (B[i] != A[tam1 - 1])
                return false;
            tam1--;
        }
        return true;
    }
}

int main() {
    int N;
    string a, b;

    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> a >> b;
        if (encaixa(a, b))
            cout << "encaixa\n";
        else
            cout << "nao encaixa\n";
    }

    // system("PAUSE");
    return 0;
}