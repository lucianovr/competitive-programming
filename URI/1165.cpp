#include <cstdlib>
#include <iostream>
using namespace std;

bool isPrime(long int num) {
    if (num == 0 || num == 1 || (num % 2 == 0 && num != 2))
        return false;
    else
        for (int j = 3; j * j <= num; j = j + 2)

            if (num % j == 0)
                return false;
    return true;
}

int main() {

    int n;
    long int x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (isPrime(x))
            cout << x << " eh primo\n";
        else
            cout << x << " nao eh primo\n";
    }

    // system( "PAUSE");
    return 0;
}
