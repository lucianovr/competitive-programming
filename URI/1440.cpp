#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
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
#define pb push_back
#define sz size()
typedef struct {
    int h, m, s;
    char e; // estado
} CARTAO;

vector<CARTAO> v;
bool comp(CARTAO a, CARTAO b) {
    if (a.h < b.h)
        return true;
    if (a.h > b.h)
        return false;
    if (a.m < b.m)
        return true;
    if (a.m > b.m)
        return false;
    if (a.s < b.s)
        return true;
    return false;
}

int main() {
    int n;
    char c;
    int pode, entrou, resp, cont;
    while (cin >> n && n) {
        v.resize(n);
        entrou = 0;
        rep(i, n) {
            cin >> v[i].h >> c >> v[i].m >> c >> v[i].s >> v[i].e;
            if (v[i].e == 'E')
                entrou++;
        }
        sort(all(v), comp);
        pode = n / 2 - entrou;
        cont = resp = 0;
        rep(i, n) {
            if (v[i].e == 'E')
                cont++;
            else if (v[i].e == 'X')
                cont--;
            else {          // ?
                if (pode) { // entra
                    pode--;
                    cont++;
                } else { // sai
                    cont--;
                }
            }
            resp = max(resp, cont);
        }

        cout << resp << endl;
    }
    return 0;
}
