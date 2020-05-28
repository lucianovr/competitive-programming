#include <iostream>
#define MAX 101
using namespace std;

int main() {

    struct Formula {
        int P[MAX];
    } G[MAX];
    int PTS[MAX], S[MAX], ns, K, g, p, ma;
    int i, j;

    while (cin >> g >> p && g + p) {
        for (i = 0; i < g; i++)
            for (j = 1; j <= p; j++) {
                cin >> G[i].P[j];
            }
        cin >> ns;
        for (int s = 0; s < ns; s++) {
            cin >> K;
            for (j = 1; j <= p; j++)
                PTS[j] = 0;
            for (j = 1; j <= K; j++)
                cin >> S[j];
            for (i = 0; i < g; i++)
                for (j = 1; j <= p; j++)
                    if (G[i].P[j] <= K)
                        PTS[j] += S[G[i].P[j]];

            ma = -1;
            for (j = 1; j <= p; j++)
                if (PTS[j] > ma)
                    ma = PTS[j];
            for (j = 1; j <= p; j++)
                if (PTS[j] == ma) {
                    cout << j;
                    break;
                }
            for (i = j + 1; i <= p; i++)
                if (PTS[i] == ma)
                    cout << " " << i;
            cout << "\n";
        }
    }
    return 0;
}
