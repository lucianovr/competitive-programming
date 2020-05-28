#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
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
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()

int main() {
    int n, qt;
    char text[100001], padrao[101];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", text);
        scanf("%d", &qt);
        while (qt--) {
            scanf("%s", padrao);
            int t = strlen(text), p = strlen(padrao), j = 0;
            for (int i = 0; i < t; i++) {
                if (text[i] == padrao[j]) {
                    j++;
                    if (j == p) {
                        printf("Yes\n");
                        break;
                    }
                }
            }
            if (j < p)
                printf("No\n");
        }
    }

    return 0;
}
