#include <iostream>
#include <map>
using namespace std;

int main() {
    int pe[65], pd[65];
    int i, bota, cont, no;
    char P;
    map<int, bool> B;
    map<int, bool>::iterator it;

    int n;
    while (cin >> n) {
        for (i = 0; i < 65; i++)
            pe[i] = pd[i] = 0;

        for (i = 0; i < n; i++) {
            cin >> bota >> P;
            B[bota] = true;
            if (P == 'E')
                pe[bota]++;
            else if (P == 'D')
                pd[bota]++;
        }
        cont = 0;
        for (it = B.begin(); it != B.end(); it++) {
            no = it->first;
            if (pe[no] != 0 && pd[no] != 0) {
                if (pe[no] == pd[no])
                    cont += pe[no]; // se pe =3 && pd =3, temos mais 3 pares
                else if (pe[no] > pd[no])
                    cont += pd[no];
                else
                    cont += pe[no];
            }
        }
        cout << cont << endl;
    }

    return 0;
}
