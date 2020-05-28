#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int K, n, m, x, y;

    while (cin >> K && K) {
        cin >> n >> m;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            if (x == n || y == m)
                cout << "divisa\n";
            else if (x > n && y > m)
                cout << "NE\n";
            else if (x > n && y < m)
                cout << "SE\n";
            else if (x < n && y > m)
                cout << "NO\n";
            else if (x < n && y < m)
                cout << "SO\n";
        }
    }
    // system("PAUSE");
    return 0;
}