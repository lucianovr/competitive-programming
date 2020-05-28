#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    double V[N];

    for (int i = 0; i < N; i++)
        cin >> V[i];

    sort(V, V + N);

    deque<double> D;
    for (int i = 0; i < N; i++)
        if (i & 1)
            D.push_front(V[i]);
        else
            D.push_back(V[i]);

    long double pi = acos(-1);
    long double area = 0, ang = 2 * pi / N;
    for (int i = 0; i < N; i++) {
        long double a = D[i], b = D[(i + 1) % N], c;
        c = a * a + b * b - 2 * a * b * cos(ang);
        c = sqrt(c);
        area += (0.25) * sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c));
    }
    cout << fixed << setprecision(3) << area << "\n";

    return 0;
}
