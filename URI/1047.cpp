#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    float hi, mi, hf, mf, MI, MF, dh, dm;

    cin >> hi >> mi >> hf >> mf;

    MI = hi * 60 + mi;
    MF = hf * 60 + mf;

    if (MF > MI) {
        dm = MF - MI;
        dh = floor(dm / 60);
        dm = dm - dh * 60;

        cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";
    }

    else {
        dm = 1440 - MI + MF;
        dh = floor(dm / 60);
        dm -= dh * 60;

        cout << "O JOGO DUROU " << dh << " HORA(S) E " << dm << " MINUTO(S)\n";
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
