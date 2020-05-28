#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define f first
#define s second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()
int bsz, sb, mb;
vector<int> B;
bool achou;
int C;

void divide(vector<int> a, int tam);
void dobra_soma(vector<int> A, int pos, int tam);
bool check(vector<int> a, int tam);

int main() {

    int asz, sa, ma;
    vector<int> A;
    while (cin >> asz) {
        int x;
        achou = false;
        sa = sb = ma = mb = 0;
        rep(i, asz) {
            cin >> x;
            A.pb(x);
            if (x > ma)
                ma = x;
            sa += x;
        }
        C = 0;
        cin >> bsz;
        rep(i, bsz) {
            cin >> x;
            B.pb(x);
            if (x > mb)
                mb = x;
            sb += x;
        }

        if (asz < bsz || ma > mb || sa > sb)
            cout << "N\n";
        else {
            divide(A, asz);
            B.clear();
            A.clear();
            if (achou == false)
                cout << "N\n";
        }
    }
    return 0;
}

void divide(vector<int> a, int tam) {

    if (achou)
        return;
    if (tam == bsz) {
        C++;
        if (check(a, tam)) {
            cout << "S\n";
            achou = true;
            return;
        }
    }
    for (int i = 1; i < tam; i++) {
        dobra_soma(a, i, max(i, tam - i));
    }
}

void dobra_soma(vector<int> A, int pos, int tam) {
    if (tam < bsz)
        return;
    vector<int> a(tam, 0);
    vector<int> b(tam, 0);
    int i, k, ma = 0;
    for (i = pos - 1, k = tam - 1; i >= 0; i--, k--) {
        a[k] = A[i];
    }
    for (i = pos, k = tam - 1; i < A.size(); i++, k--) {
        b[k] = A[i];
    }
    rep(i, tam) {
        a[i] += b[i];
        if (a[i] > ma)
            ma = a[i];
    }
    if (ma > mb)
        return;
    else
        divide(a, tam);
}

bool check(vector<int> a, int tam) {
    int cont = 0;
    rep(i, tam) if (a[i] != B[i]) {
        cont = 1;
        break;
    }
    reverse(all(a));
    vector<int> b = a;
    rep(i, tam) if (b[i] != B[i]) {
        cont++;
        break;
    }
    if (cont < 2)
        return true;
    else
        return false;
}