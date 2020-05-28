#include <cstdlib>
#include <iostream>

using namespace std;
int N, ta, tb;
string a, b;

void Alterna(int t) {
    int i, ac = 0, bc = 0;
    string c;
    for (i = 0; i < 2 * t; i++)
        if (i % 2 == 0) {
            c += a[ac];
            ac++;
        } else {
            c += b[bc];
            bc++;
        }

    if (ta != tb) {
        if (ta > tb)
            for (i = t; i < ta; i++)
                c += a[i];
        else
            for (i = t; i < tb; i++)
                c += b[i];
    }

    cout << c << endl;

    return;
}
int main() {

    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> a >> b;
        ta = a.size();
        tb = b.size();
        if (ta < tb)
            Alterna(ta);
        else
            Alterna(tb);
    }

    // system("PAUSE");
    return 0;
}
