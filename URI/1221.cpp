#include <cstdlib>
#include <iostream>

using namespace std;

bool VerificaPRIMO(unsigned long long int num) {
    for (int i = 3; i * i <= num; i = i + 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    unsigned long long int x;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (VerificaPRIMO(x))
            cout << "Prime\n";
        else
            cout << "Not Prime\n";
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}
