#include <algorithm>
#include <cstring>
#include <queue>
#include <stdio.h>
#include <string.h>
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
#define contem(s, x) (s.find(x) != s.end())
char w[2010];

int main() {
    int n;
    scanf("%d", &n);
    scanf("\n");
    while (n--) {
        gets(w);
        int wlen = strlen(w);

        rep(i, wlen) {
            if (w[i] == ' ' || w[i] == '0') {
                int j = i;
                while (j < wlen && w[j] == w[i])
                    j++;
                int q = j - i;
                if (q == 1)
                    printf("%c", w[i]);
                else if (q == 2)
                    printf("%c%c", w[i], w[i]);
                else {
                    while (q >= 255) {
                        printf("%c", w[i] == '0' ? '#' : '$');
                        printf("%c", 255);
                        q -= 255;
                    }
                    if (q)
                        printf("%c%c", w[i] == '0' ? '#' : '$', q);
                }
                i = j - 1;
            } else
                printf("%c", w[i]);
            ;
        }
        printf("\n");
    }
    return 0;
}