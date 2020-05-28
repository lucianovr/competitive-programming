#include <bitset>
#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b;

    while (cin >> a >> b)
        cout << (((bitset<32>)a) ^ ((bitset<32>)b)).to_ulong() << endl;

    return 0;
}
