#include <algorithm>
#include <iostream>

using namespace std;
int n, N, P[1000000], I[1000000], p, i, num;

int main() {
    cin >> N;
    i = p = -1;
    for (n = 0; n < N; n++) {

        cin >> num;
        if (num % 2 == 0) {
            p++;
            P[p] = num;
        } else {
            i++;
            I[i] = num;
        }
    }

    sort(P, P + p + 1);
    sort(I, I + i + 1);

    for (n = 0; n <= p; n++)
        cout << P[n] << "\n";
    for (n = i; n >= 0; n--)
        cout << I[n] << "\n";

    //  system("PAUSE");
    return 0;
}
