// Strings STRTOK
// mapeamento

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int num[] = {64,  129, 130, 131, 132, 133, 134, 135, 136, 137, 145, 146, 147, 148, 149, 150, 151,
             152, 153, 162, 163, 164, 165, 166, 167, 168, 169, 192, 193, 194, 195, 196, 197, 198,
             199, 200, 201, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 226, 227, 228, 229,
             230, 231, 232, 233, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249};
char alfanum[] = {" abcdefghijklmnopqrstuvwxyz{ABCDEFGHI}JKLMNOPQRSTUVWXYZ0123456789"};
char mapa[300];

void constroi() {
    int len = strlen(alfanum);
    rep(i, 0, len) mapa[num[i]] = alfanum[i];

    //	rep(i,0,len) cout << num[i] << " " << mapa[ num[i] ] << "\n";
}

int main() {
    constroi();

    char s[10000], *pc;

    while (gets(s)) {
        pc = strtok(s, " ");

        while (pc != NULL) {
            int value = (pc[0] - '0') * 64 + (pc[1] - '0') * 8 + (pc[2] - '0');
            printf("%c", mapa[value]);
            pc = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}
