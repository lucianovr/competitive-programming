#include <cstring>
#include <iostream>
using namespace std;
int main() {
    string spc3 = "   ", spc2 = "  ";
    int n, v[110];

    while (cin >> n && n) {

        int i, j = 1;
        for (i = 0; i < n; i++)
            v[i] = 0;

        for (j = 0; j < n / 2; j++) {
            for (i = 0; i < n; i++) {
                if (i >= j && i < n - j)
                    v[i]++;
                if (v[i] < 10 && i != 0)
                    cout << spc3;
                else if (v[i] < 100)
                    cout << spc2;
                cout << v[i];
            }
            cout << endl;
        }

        if (n % 2 == 1) {
            v[n / 2]++;
            for (i = 0; i < n; i++) {
                if (v[i] < 10 && i != 0)
                    cout << spc3;
                else if (v[i] < 100)
                    cout << spc2;
                cout << v[i];
            }
            cout << endl;
        }

        int k = j;
        for (j = 0; j < n / 2; j++) {
            for (i = 0; i < n; i++) {
                if (i >= k && i < n - k)
                    v[i]--;
                if (v[i] < 10 && i != 0)
                    cout << spc3;
                else if (v[i] < 100)
                    cout << spc2;
                cout << v[i];
            }
            cout << endl;
            k--;
        }
        cout << endl;
    }
    return 0;
}
