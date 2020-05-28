#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back

bool QP(int x) { // quadrado perfeito ?
    int u = sqrt(x);
    return u * u == x;
}
int v[55];

int main() {
    int size = 0, val = 1, tam[55];
    bool mudou;

    for (int i = 1; i <= 50; i++) {
        mudou = true;
        while (mudou) {
            mudou = false;
            Rep(j, i) {
                if (QP(val + v[j]) || v[j] == 0) {
                    size++;
                    v[j] = val;
                    val++;
                    mudou = true;
                    tam[i] = size;
                    break;
                }
            }
        }
    }

    int t, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        printf("%d\n", tam[x]);
    }

    return 0;
}
