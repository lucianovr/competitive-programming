#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, bool> armadilha;
    int P, S, t1, t2, t3, N, d1, d2;
    int p[10];
    bool j[10];

    while (cin >> P >> S && P + S) {
        armadilha.clear();
        cin >> t1 >> t2 >> t3;
        armadilha[t1] = true;
        armadilha[t2] = true;
        armadilha[t3] = true;

        cin >> N;
        int i = 0, id = -1, flag = 1;
        for (int n = 0; n < P; n++) {
            j[n] = true;
            p[n] = 0;
        }

        for (int n = 0; n < N; n++) {
            cin >> d1 >> d2;
            while (!j[i]) {
                j[i] = true;
                i = (i + 1) % P;
            }
            p[i] = p[i] + d1 + d2;
            if (armadilha[p[i]])
                j[i] = false;
            if (flag == 1 && j[i] && p[i] > S) {
                id = i + 1;
                flag = 0;
            }

            i = (i + 1) % P;
        }
        cout << id << endl;
    }
    return 0;
}
