#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

double calPF(double th, double v, double H) {
    double g = 9.80665, d, t;

    d = pow(v * sin(th), 2) + 2 * g * H;

    t = (v * sin(th) - sqrt(d)) / g;
    if (t < 0)
        t = (v * sin(th) + sqrt(d)) / g;

    return v * cos(th) * t;
}

int main() {
    double pi = 3.14159, h, alpha, vel, theta, x;
    int n, p1, p2;

    while (cin >> h) {
        cin >> p1 >> p2;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> alpha >> vel;
            theta = alpha * (pi / 180.0);
            x = calPF(theta, vel, h);

            cout << fixed << setprecision(5);
            if (x >= p1 && x <= p2)
                cout << x << " -> DUCK\n";
            else
                cout << x << " -> NUCK\n";
        }
    }
    return 0;
}