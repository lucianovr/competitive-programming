#include <algorithm>
#include <cmath> // atan2(dy,dx) :retorna angulo polar
#include <cstdlib>
#include <iostream>
#include <set>
#include <string.h>
#include <string>
#include <utility> // #define x first , y second  quando trabalhar com pontos
#include <vector>  // #include <map> , <set> , <stack> , <queue> , <deque>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

int main() {

    int c;
    cin >> c;
    cin.ignore();
    string f;
    set<char> s;

    while (c--) {
        s.clear();
        getline(cin, f);

        int len = f.size();
        rep(i, len) {
            if (f[i] >= 'a' && f[i] <= 'z')
                s.insert(f[i]);
        }

        len = s.size();

        if (len == 26)
            cout << "frase completa\n";
        else if (len >= 13)
            cout << "frase quase completa\n";
        else
            cout << "frase mal elaborada\n";
    }
}
