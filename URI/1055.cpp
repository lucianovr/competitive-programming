#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

bool comp(int i, int j) { return (i > j); }

int ABS(int x) {
    if (x > 0)
        return x;
    return -x;
}

int main() {

    int tc, n, vet[51], i, last, first, soma, maL, maF;
    deque<int> dq;

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        dq.clear();
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> vet[i];
        sort(vet, vet + n, comp);

        dq.push_front(vet[0]);
        vet[0] = -1;
        first = 1, last = n - 1;

        while (true) {
            if (vet[last] == -1 || vet[first] == -1)
                break;

            maL = max(ABS(vet[last] - dq.back()), ABS(vet[last] - dq.front()));
            maF = max(ABS(vet[first] - dq.back()), ABS(vet[first] - dq.front()));

            if (maL > maF) {
                if (ABS(vet[last] - dq.back()) > ABS(vet[last] - dq.front()))
                    dq.push_back(vet[last]);
                else
                    dq.push_front(vet[last]);
                vet[last] = -1;
                last--;
            } else {
                if (ABS(vet[first] - dq.back()) > ABS(vet[first] - dq.front()))
                    dq.push_back(vet[first]);
                else
                    dq.push_front(vet[first]);
                vet[first] = -1;
                first++;
            }
        }
        i = 0;
        for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
            vet[i++] = *it;

        soma = 0;

        for (i = 1; i < n; i++)
            soma += ABS(vet[i] - vet[i - 1]);
        cout << "Case " << t << ": " << soma << endl;
    }
    return 0;
}
