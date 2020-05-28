#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

string reg, U, D, L, R;

void up(int i) {
    if (i == 0) {
        U[0] = '1';
        return;
    }
    if (reg[i] == 'p') {
        up(i - 1);
        U[i] = 's';
        return;
    } else if (reg[i] == 'q') {
        up(i - 1);
        U[i] = 'r';
    } else if (reg[i] == 's') {
        U[i] = 'p';
    } else if (reg[i] == 'r') {
        U[i] = 'q';
    }
}

void down(int i) {
    if (i == 0) {
        D[0] = '1';
        return;
    } else if (reg[i] == 'p') {
        D[i] = 's';
    } else if (reg[i] == 'q') {
        D[i] = 'r';
    } else if (reg[i] == 's') {
        down(i - 1);
        D[i] = 'p';
    } else if (reg[i] == 'r') {
        down(i - 1);
        D[i] = 'q';
    }
}

void left(int i) {
    if (i == 0) {
        L[0] = '1';
        return;
    } else if (reg[i] == 'p') {
        left(i - 1);
        L[i] = 'q';
    } else if (reg[i] == 'q') {
        L[i] = 'p';
    } else if (reg[i] == 's') {
        left(i - 1);
        L[i] = 'r';
    } else if (reg[i] == 'r') {
        L[i] = 's';
    }
}

void right(int i) {
    if (i == 0) {
        R[0] = '1';
        return;
    } else if (reg[i] == 'p') {
        R[i] = 'q';
    } else if (reg[i] == 'q') {
        right(i - 1);
        R[i] = 'p';
    } else if (reg[i] == 's') {
        R[i] = 'r';
    } else if (reg[i] == 'r') {
        right(i - 1);
        R[i] = 's';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        cin >> reg;
        int k = reg.size() - 1;
        U = D = L = R = reg;
        up(k);
        if (U[0] == '1')
            U = "<none>";
        down(k);
        if (D[0] == '1')
            D = "<none>";
        left(k);
        if (L[0] == '1')
            L = "<none>";
        right(k);
        if (R[0] == '1')
            R = "<none>";

        printf("%s %s %s %s\n", U.c_str(), D.c_str(), L.c_str(), R.c_str());
    }
    return 0;
}
