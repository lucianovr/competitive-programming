#include <algorithm>
#include <cmath> // atan2(dy,dx) :retorna angulo polar
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility> // #define x first , y second  quando trabalhar com pontos
#include <vector>  // #include <map> , <set> , <stack> , <queue> , <deque>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

int main() {

    int n, k, a;

    while (cin >> n >> k && n + k) {
        int q[n];
        rep(j, n) q[j] = 0;
        rep(j, n) {
            cin >> a;
            q[a - 1]++;
        }
        int out = 0;
        rep(j, n) {
            if (q[j] >= k) {
                out++;
            }
        }

        cout << out << endl;
    }
}
