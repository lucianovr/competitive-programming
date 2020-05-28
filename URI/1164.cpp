#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n;
    unsigned long long soma = 0ULL, num;
    cin >> n;

    for (int j = 0; j < n; j++) {
        cin >> num;
        soma = 0ULL;
        for (int i = 1; i < num; i++)
            if (num % i == 0)
                soma = soma + i;

        if (soma == num)
            cout << num << " eh perfeito\n";
        else
            cout << num << " nao eh perfeito\n";
    }

    // system ("PAUSE");
    return 0;
}