#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int n;
    cin >> n;
    if (n) {
        printf("Ho");
        n--;
        while (--n >= 0)
            printf(" Ho");
        printf("!\n");
    }
    return 0;
}
