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
    int casos;
    int n, valor;
    int min, id, x, dif;

    cin >> casos;
    while (casos--) {
        min = 1000000000;
        cin >> n >> valor;

        rep(i, n) {
            cin >> x;
            dif = abs(x - valor);
            if (min > dif) {
                min = dif;
                id = i;
            }
        }

        cout << id + 1 << endl;
    }
}
