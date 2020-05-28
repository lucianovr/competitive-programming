#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

string func(int m, int n) {
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++) {
            if (i * i + j * j == n)
                return "YES";
        }
    return "NO";
}

int main()

{

    int n;
    while (cin >> n) {
        int max = int(sqrt(n));
        if (n < 0)
            cout << "NO\n";
        else
            cout << func(max, n) << endl;
    }

    return 0;
}