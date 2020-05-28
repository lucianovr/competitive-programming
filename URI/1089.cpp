#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int v[n], cont = 0;
        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 1; i < n - 1; i++)
            if ((v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1]))
                cont++;
        if ((v[0] > v[1] && v[0] > v[n - 1]) || (v[0] < v[1] && v[0] < v[n - 1]))
            cont++;
        if ((v[n - 1] > v[0] && v[n - 1] > v[n - 2]) || (v[n - 1] < v[0] && v[n - 1] < v[n - 2]))
            cont++;

        cout << cont << endl;
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}