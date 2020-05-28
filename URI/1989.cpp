#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define contains(s, x) (s.find(x) != s.end())

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == -1)
            break;

        vector<unsigned long long> V(N + 1);
        rep(i, 1, N + 1) cin >> V[i];

        unsigned long long soma = 0, J = N;
        rep(i, 1, N + 1) {
            soma += J * V[i] * M;
            J--;
        }
        cout << soma << "\n";
    }

    return 0;
}
