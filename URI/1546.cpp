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

    int n, k, feed;

    cin >> n;
    rep(j, n) {

        cin >> k;

        rep(i, k) {
            cin >> feed;

            switch (feed) {
            case 1:
                cout << "Rolien" << endl;
                break;
            case 2:
                cout << "Naej" << endl;
                break;
            case 3:
                cout << "Elehcim" << endl;
                break;
            case 4:
                cout << "Odranoel" << endl;
                break;
            }
        }
    }
}
