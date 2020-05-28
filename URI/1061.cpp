#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int d, h, m, s, d2, h2, m2, s2;
    int D, H, M, S;
    long long int ts, ts2, vt;
    string buf;

    cin >> buf >> d;
    cin >> h >> buf >> m >> buf >> s;

    cin >> buf >> d2;
    cin >> h2 >> buf >> m2 >> buf >> s2;

    ts = d * 86400 + h * 3600 + m * 60 + s;
    ts2 = d2 * 86400 + h2 * 3600 + m2 * 60 + s2;
    vt = ts2 - ts;

    D = floor(vt / 86400);
    vt = vt - D * 86400;
    H = floor(vt / 3600);
    vt -= H * 3600;
    M = floor(vt / 60);
    vt -= M * 60;
    S = vt;

    cout << D << " dia(s)\n";
    cout << H << " hora(s)\n";
    cout << M << " minuto(s)\n";
    cout << S << " segundo(s)\n";

    // system("PAUSE");
    return 0;
}
