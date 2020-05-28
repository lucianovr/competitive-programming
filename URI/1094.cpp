#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    float n, qt, s = 0, r = 0, c = 0, tot = 0;
    string a;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> qt >> a;
        tot += qt;

        if (a[0] == 'S')
            s += qt;
        else if (a[0] == 'C')
            c += qt;
        else if (a[0] == 'R')
            r += qt;
    }
    cout << "Total: " << tot << " cobaias\n";
    cout << "Total de coelhos: " << c << endl;
    cout << "Total de ratos: " << r << endl;
    cout << "Total de sapos: " << s << endl;
    cout << fixed << setprecision(2);
    cout << "Percentual de coelhos: " << (c * 100) / tot << " %\n";
    cout << "Percentual de ratos: " << (r * 100) / tot << " %\n";
    cout << "Percentual de sapos: " << (s * 100) / tot << " %\n";
    // system("PAUSE");
    return 0;
}