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

bool comp(int a, int b) { return a > b; }

int main() {

    int t, n;
    vi v, notas;

    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n);
        notas.resize(n);

        rep(i, n) {
            cin >> v[i];
            notas[i] = v[i];
        }
        sort(v.begin(), v.end(), comp);
        int cont = 0;

        rep(i, n) {
            if (notas[i] == v[i])
                cont++;
        }
        cout << cont << endl;
    }

    return 0;
}
