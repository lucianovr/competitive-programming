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

int main() {
    int n, m, a, b;
    string line[51];
    while (cin >> n >> m && n + m) {
        cin.ignore();
        rep(i, n) { getline(cin, line[i]); }
        cin >> a >> b;
        int nn, mm;
        nn = a / n;
        mm = b / m;
        string s, aux;
        rep(i, n) {
            s.clear();
            aux = line[i];
            for (int j = 0; j < m; j++)
                rep(k, mm) s += aux[j];
            rep(k, nn) cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}
