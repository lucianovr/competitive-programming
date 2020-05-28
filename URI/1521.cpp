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
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()

int main() {
    int n;
    int v[100];
    int k;

    while (cin >> n && n) {

        for (int i = 1; i <= n; i++)
            cin >> v[i];
        cin >> k;

        while (k != v[k]) {
            k = v[k];
        }
        cout << k << endl;
    }
    return 0;
}
