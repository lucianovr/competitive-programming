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
#define rep(i, n) for (int i = 0, j = (n); i < j; i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()

int main() {
    int n;
    vector<string> vec;
    string atual, abaixo;
    int cont, len;
    while (cin >> n) {
        vec.resize(n);
        rep(i, n) cin >> vec[i];
        sort(all(vec));
        cont = 0;
        len = vec[0].sz;
        rep(i, n - 1) {
            atual = vec[i], abaixo = vec[i + 1];
            rep(i, len) {
                if (atual[i] == abaixo[i])
                    cont++;
                else
                    break;
            }
        }
        cout << cont << endl;
    }
    return 0;
}
