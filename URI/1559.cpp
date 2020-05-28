#include <cstdlib>

#include <iostream>

#include <stdio.h>

#include <cstring>

#include <vector>

#include <algorithm>

#include <utility>

#include <queue>

#include <map>

#include <stack>

#include <cmath>

#include <set>

#define INF 99999999

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)

#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define tr(it, s) for (typeof(s.begin()) it = s.begin(); it != s.end(); it++)

#define pb push_back

#define clr(a) memset((a), 0, sizeof(a))

#define pi 3.1415926535897932384626433832795028841971

using namespace std;

typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

int n;

int m[5][5];

char op[4];

bool left() {

    rep(i, 0, 4) {

        int atual = m[i][3];

        for (int j = 2; j >= 0; j--) {

            if (((atual == m[i][j]) && atual) || atual != 0 && m[i][j] == 0)

                return true;

            else

                atual = m[i][j];
        }
    }

    return false;
}

bool right() {

    rep(i, 0, 4) {

        int atual = m[i][0];

        for (int j = 1; j <= 3; j++) {

            if (((atual == m[i][j]) && atual) || atual != 0 && m[i][j] == 0)

                return true;

            else

                atual = m[i][j];
        }
    }

    return false;
}

bool down() {

    rep(j, 0, 4) {

        int atual = m[0][j];

        for (int i = 1; i <= 3; i++) {

            if (((atual == m[i][j]) && atual) || atual != 0 && m[i][j] == 0)

                return true;

            else

                atual = m[i][j];
        }
    }

    return false;
}

bool up() {

    rep(j, 0, 4) {

        int atual = m[3][j];

        for (int i = 2; i >= 0; i--) {

            if (((atual == m[i][j]) && atual) || atual != 0 && m[i][j] == 0)

                return true;

            else

                atual = m[i][j];
        }
    }

    return false;
}

int main() {

    while (scanf("%d", &n) != EOF) {

        bool l, r, u, d;

        getchar();

        while (n--) {

            bool dois = false;

            rep(i, 0, 4)

                rep(j, 0, 4) {

                scanf("%d", &m[i][j]);

                if (m[i][j] == 2048)

                    dois = true;
            }

            l = left();

            r = right();

            d = down();

            u = up();

            bool flag = false;

            if (dois) {
                cout << "NONE" << endl;
                continue;
            }

            if (d) {
                cout << "DOWN";
                flag = true;
            }

            if (l) {

                if (flag)
                    cout << " ";

                cout << "LEFT";

                flag = true;
            }

            if (r) {
                if (flag)
                    cout << " ";
                cout << "RIGHT";
                flag = true;
            }

            if (u) {
                if (flag)
                    cout << " ";
                cout << "UP";
                flag = true;
            }

            if (!d && !l && !r && !u)
                cout << "NONE";

            printf("\n");
        }
    }

    // system("pause");

    return 0;
}