#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())

string func(int n, int v) {
    if (n == 1)
        return "possivel";
    for (int i = 2; i <= v; i++) {
        int atual = 0, vel = i;
        while (vel) {
            int vezes = vel;
            while (vezes-- && atual <= n) {
                atual += vel;
                if (atual == n)
                    return "possivel";
            }
            vel--;
        }
    }
    return "impossivel";
}

int main() {
    int n, v;
    while (cin >> n >> v && n + v) {
        vi dist(n + 1, 0);
        cout << func(n, v) << endl;
    }
    return 0;
}
