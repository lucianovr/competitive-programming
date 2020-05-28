
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
    int i, g, vi = 0, vg = 0, em = 0, n = 1, cont = 0;

    while (n == 1) {
        cont++;
        cin >> i >> g;
        if (i == g)
            em++;
        else if (i > g)
            vi++;
        else
            vg++;
        cout << "Novo grenal (1-sim 2-nao)\n";
        cin >> n;
    }
    cout << cont++ << " grenais\n";
    cout << "Inter:" << vi << endl;
    cout << "Gremio:" << vg << endl;
    cout << "Empates:" << em << endl;
    if (vi > vg)
        cout << "Inter venceu mais\n";
    else if (vi == vg)
        cout << "Nao houve vencedor\n";
    else
        cout << "Gremio venceu mais\n";
    // system("PAUSE");
    return 0;
}
